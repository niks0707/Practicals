import socket
import threading

# Define the server's host and port
HOST = 'localhost'
PORT = 12345

# Create a socket for the server
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((HOST, PORT))
server_socket.listen()

print(f"Server is listening on {HOST}:{PORT}")

# Function to handle client connections
def handle_client(client_socket):
    print(f"Accepted connection from {client_socket.getpeername()}")

    while True:
        try:
            # Receive data from the client
            data = client_socket.recv(1024).decode('utf-8')

            if not data:
                break

            # Split the received data into operation and parameters
            operation, *params = data.split()

            if operation == "compare":
                if len(params) != 2:
                    client_socket.send("Invalid number of parameters for compare operation.".encode('utf-8'))
                else:
                    result = str(params[0] == params[1])
                    client_socket.send(result.encode('utf-8'))

            elif operation == "count":
                if len(params) != 1:
                    client_socket.send("Invalid number of parameters for count operation.".encode('utf-8'))
                else:
                    result = str(len(params[0]))
                    client_socket.send(result.encode('utf-8'))

            else:
                client_socket.send("Invalid operation.".encode('utf-8'))

        except Exception as e:
            print(f"Error: {e}")
            break

    print(f"Connection from {client_socket.getpeername()} closed.")
    client_socket.close()

# Main server loop
while True:
    client_socket, client_address = server_socket.accept()
    client_handler = threading.Thread(target=handle_client, args=(client_socket,))
    client_handler.start()
