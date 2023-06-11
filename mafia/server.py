import time
import socket
import threading
import pika
import grpc
import proto.server_pb2_grpc as server_pb2_grpc
import proto.server_pb2 as server_pb2
import proto.notify_server_pb2_grpc as notify_server_pb2_grpc
import proto.notify_server_pb2 as notify_server_pb2
from concurrent import futures

mutex = threading.Lock()

class User:
    def __init__(self, username, uuid, session_id, hostname, port):
        self.uuid = uuid
        self.username = username
        self.session_id = session_id
        self.hostname = hostname
        self.port = port
        self.role = "user" # TODO for mafia

    def is_secret(self):
        return True # TODO 


class Session:
    def __init__(self, id):
        self.id = id
        self.users = {}

    def full(self):
        return len(self.users) == 1

    def add_user(self, user: User):
        self.users[user.uuid] = user


class Server(server_pb2_grpc.ServerServicer):
    def __init__(self, *args, **kwargs):
        self.sessions = []
        self.users = 0
        self.session_id = 0
        self.last_updated = 0

        try_count = 0
        while True and try_count < 20:
            try:
                rabbit_connection = pika.BlockingConnection(pika.ConnectionParameters(host='rabbitmq'))
                self.notify_rabbit_ch = rabbit_connection.channel()
                break
            except:
                print(f"couldn't connect to rabbitmq for {try_count}'th time")
                time.sleep(1)
            try_count += 1


        self.notify_host = 'notify_server'
        self.notify_port = 3001
        self.notify_grpc_ch = grpc.insecure_channel(
            '{}:{}'.format(self.notify_host, self.notify_port))
        self.notify_stub = notify_server_pb2_grpc.NotifyServerStub(self.notify_grpc_ch)

        print("init done")

    def get_session_id(self):
        if len(self.sessions) == 0 or self.sessions[-1].full():
            self.sessions.append(Session(self.session_id))
            self.session_id += 1
        return self.sessions[-1].id

    def need_new_session(self):
        return len(self.sessions) == 0 or self.sessions[-1].full()

    def Register(self, request, context):
        print("got new register request")
        mutex.acquire()
        needed_new_session = self.need_new_session()
        session_id = self.get_session_id()

        if len(request.username) == 0:
            username = "anonymous"
        else:
            username = request.username
        
        user = User(username, request.uuid, session_id, request.hostname, request.port)
        self.sessions[session_id].add_user(user)

        if needed_new_session:
            self.notify_rabbit_ch.queue_declare('session_'+str(session_id))

            notify_request = notify_server_pb2.RegisterSessionRequest()
            notify_request.session_id = session_id
            for uuid in self.sessions[session_id].users:
                notify_request.uuids.append(uuid)
                notify_request.usernames.append(self.sessions[session_id].users[uuid].username)
                notify_request.secret.append(self.sessions[session_id].users[uuid].is_secret())
                notify_request.hosts.append(self.sessions[session_id].users[uuid].hostname)
                notify_request.ports.append(self.sessions[session_id].users[uuid].port)
            
            mutex.release()

            response = self.notify_stub.RegisterSession(notify_request)
        else:
            mutex.release()
        return server_pb2.RegisterResponse(username=username, session_id=session_id, role=user.role)

    def UserMessage(self, request, context):
        print("got UserMessage request")
        mutex.acquire()
        session_id = request.session_id
        if session_id < 0 or session_id >= len(self.sessions):
            context.set_code(grpc.StatusCode.NOT_FOUND)
            context.set_details('Session id not found')
            mutex.release()
            return
        session = self.sessions[session_id]

        uuid = request.uuid
        if uuid not in session.users:
            context.set_code(grpc.StatusCode.NOT_FOUND)
            context.set_details('User uuid not found in session')
            mutex.release()
            return

        if request.secret and not session.users[uuid].is_secret():
            context.set_code(grpc.StatusCode.INVALID_ARGUMENT)
            context.set_details('You are not allowed to send secret messages')
            mutex.release()
            return

        secret_prefix = "1" if request.secret else "0"

        message = secret_prefix + session.users[uuid].username + ": " + request.message
        mutex.release()

        print("queue_id=", ('session_'+str(session_id)))
        self.notify_rabbit_ch.basic_publish(
            exchange='', routing_key=('session_'+str(session_id)), body=message)
        return server_pb2.UserMessageResponse()

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    server_pb2_grpc.add_ServerServicer_to_server(Server(), server)
    server.add_insecure_port('[::]:2001')
    server.start()
    server.wait_for_termination()

if __name__ == '__main__':
    serve()