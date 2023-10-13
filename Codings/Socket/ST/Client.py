import socket

# Main client function
def main():
    # Create a socket and connect to the server
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = 'localhost'
    port = 12345
    client_socket.connect((host, port))

    
    while True:
        # Get user input
        message = input("Enter a message (or 'quit' to exit): ")
        
        if message.lower() == 'quit':
            break

        # Send the message to the server
        client_socket.send(message.encode('utf-8'))

        # Receive and print the modified message from the server
        modified_message = client_socket.recv(1024).decode('utf-8')
        print(f"Modified Message from Server: {modified_message}")

    client_socket.close()

if __name__ == "__main__":
    main()
