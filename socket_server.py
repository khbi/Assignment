import socket
import sys
import argparse

host = '127.0.0.1'
data_payload = 2048
backlog = 5
error = '0x0aASA3'

def echo_server(port):
        # Create a TCP socket
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        # Enable reuse address/port
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        # Bind the socket to the port
        server_address = (host, port)     
        print("Waiting for client...")
        sock.bind(server_address)
        #Listen to clients
        sock.listen(backlog)
        client, address = sock.accept()

        print("connected to client")

        while True:
            print("Waiting to receive message from client")
            data = client.recv(1024).decode('utf-8')
            if data == 'bye':
                print("Closing connection to the client(bye)")
                client.send(error.encode('utf-8'))
                sock.close()
                sys.exit()
            elif data == '0x0aASA3':
                print("Closing connection to the client(bye)")
                sock.close()
                sys.exit()    
            else:
                print("Received message from client")
                print("client >> ", data)
                print("")
                message = input('You>  ')
                client.send(message.encode('utf-8'))
                

if __name__ == '__main__':
        parser = argparse.ArgumentParser(description='socket server example')
        parser.add_argument('--port', action="store", dest="port", type=int, required=True)
        given_args = parser.parse_args()
        port = given_args.port
        echo_server(port)
        