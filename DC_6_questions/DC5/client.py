import socket

# Main client function
def main():
    # Create a socket and connect to the server
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = 'localhost'
    port = 12345
    client_socket.connect((host, port))

    
    print("Available operations: 1- sqrt, 2 - square, 3 - factorial")
    operation = input("Enter the operation you want to perform (q to quit): ")

    if operation == 'q':
        print('Exiting...')
        return

    number = int(input("Enter the number : "))

        # Send the operation and number to the server
    data = "{} {}".format(operation, number)
    client_socket.send(data.encode('utf-8'))

        # Receive and print the result from the server
    result = client_socket.recv(1024).decode('utf-8')
    print("Result: {}".format(result))

    # Close the client socket
    client_socket.close()

if __name__ == "__main__":
    main()
