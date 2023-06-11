from contextlib import closing
import socket
import grpc
import proto.server_pb2_grpc as server_pb2_grpc
import proto.server_pb2 as server_pb2
import uuid

def find_free_port():
    with closing(socket.socket(socket.AF_INET, socket.SOCK_STREAM)) as s:
        s.bind(('', 0))
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        return s.getsockname()[1]

class Client:
    def __init__(self):
        self.user_name = ''
        self.session_id = 0
        self.port = 0
        self.uuid = str(uuid.uuid4())
        self.role = ''

        self.host = 'localhost'
        self.server_port = 2001
        self.channel = grpc.insecure_channel(
            '{}:{}'.format(self.host, self.server_port))
        self.stub = server_pb2_grpc.ServerStub(self.channel)

    def run(self):
        self.port = find_free_port()
        sock = socket.socket()
        sock.bind(('', self.port))
        sock.listen(1)

        print("got port:", self.port)
        
        register_request = server_pb2.RegisterRequest()
        register_request.username = 'Aboba'
        register_request.hostname = self.host
        register_request.port = self.port
        register_request.uuid = self.uuid

        response = self.stub.Register(register_request)
        self.session_id = response.session_id
        self.role = response.role

        print("created registration")
        while True:
            message_request = server_pb2.UserMessageRequest()
            message_request.uuid = self.uuid
            message_request.session_id = self.session_id
            message_request.message = "All work and no play makes Jack a dull boy"
            message_request.secret = True
            response = self.stub.UserMessage(message_request)

            client, addr = sock.accept()

            data = client.recv(1024)
            print('client addr: ', data)
            client.close()


def main():
    client = Client()
    client.run()


if __name__ == "__main__":
    main()
