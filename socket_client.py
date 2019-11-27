import socket
import sys
import argparse

host = '127.0.0.1'
error = '0x0aASA3'

def echo_client(port):
        #Create a TCP/IP socket
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        #Connection the socket to the server
        server_address = (host, port)
        sock.connect(server_address)

        print("Connected to server")
        
        while True:
            #Send data
            message=input('You> ')
            sock.send(message.encode('utf-8'))
            print("Waiting to server ")

            #Recieve data
            data = sock.recv(1024).decode('utf-8')
            if data == 'bye':
                print("Closing connection to the server(bye)")
                sock.send(error.encode('utf-8'))
                sock.close()
                sys.exit()
            elif data == '0x0aASA3':
                print("Closing connection to the server")
                sock.close()
                sys.exit()
            else:
                print("Received message from server")
                print("server >> ", data)
                print("")
                
                        
if __name__ == '__main__':
        parser = argparse.ArgumentParser(description='socket client example')
        parser.add_argument('--port', action="store", dest="port", type=int, required=True)
        given_args = parser.parse_args()
        port = given_args.port
        echo_client(port)
        