import time
import socket
import threading
import pika
import grpc
import proto.notify_server_pb2_grpc as server_pb2_grpc
import proto.notify_server_pb2 as server_pb2
from concurrent import futures

mutex = threading.Lock()

class User:
    def __init__(self, username, uuid, session_id, hostname, port, secret):
        self.uuid = uuid
        self.username = username
        self.session_id = session_id
        self.hostname = hostname
        self.port = port
        self.secret = secret

class Session:
    def __init__(self, id):
        self.id = id
        self.users = []


class NotifyServer(server_pb2_grpc.NotifyServerServicer):

    def __init__(self, *args, **kwargs):
        self.sessions = {}
        self.users = [User]

        try_count = 0
        while True and try_count < 20:
            try:
                rabbit_connection = pika.BlockingConnection(pika.ConnectionParameters(host='rabbitmq'))
                self.rabbit_ch = rabbit_connection.channel()
                break
            except:
                print(f"couldn't connect to rabbitmq for {try_count}'th time")
                time.sleep(1)
                try_count += 1


    def RegisterSession(self, request, context):
        mutex.acquire()
        new_session = Session(request.session_id)
        for i in range(len(request.uuids)):
            new_user = User(request.usernames[i], request.uuids[i], request.session_id,
                            request.hosts[i], request.ports[i], request.secret[i])
            new_session.users.append(new_user)

        self.sessions[new_session.id] = request.session_id

        queue_name = 'session_'+str(request.session_id)
        print("queue_name=", queue_name)
        self.rabbit_ch.queue_declare(queue=queue_name)
        self.rabbit_ch.basic_consume(on_message_callback=lambda body: self.rabitmq_callback(body, request.session_id),
                      queue=queue_name,
                      auto_ack=True)
        mutex.release()

        return server_pb2.RegisterSessionResponse()

    def rabitmq_callback(self, body, session_id):
        print("wow")
        
        session = self.sessions[session_id]
        body = body[1:]
        for user in session.users:
            sock = socket.socket()
            sock.connect((user.hostname, user.port))
            sock.sock.send(body.encode("utf-8"))


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    server_pb2_grpc.add_NotifyServerServicer_to_server(NotifyServer(), server)
    server.add_insecure_port('[::]:3001')
    server.start()
    server.wait_for_termination()

if __name__ == '__main__':
    serve()