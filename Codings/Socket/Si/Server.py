import socket

# Function to calculate simple interest
def calculate_simple_interest(principal, rate, time):
    return (principal * rate * time) / 100

# Main server function
def main():
    # Create a socket and bind it to a specific host and port
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = 'localhost'
    port = 12345
    server_socket.bind((host, port))

    # Listen for incoming connecctions
    server_socket.listen(5)
    print("Server is listening on {}:{}".format(host, port))

    while True:
        # Accept a client connection
        client_socket, addr = server_socket.accept()
        print("Accepted connection from {}:{}".format(addr[0], addr[1]))

        # Receive the principal, rate, and time from the client
        data = client_socket.recv(1024).decode('utf-8')
        if data == '':
            print("Disconnected - from {}:{}".format(addr[0], addr[1]))
            continue
        principal, rate, time = map(float, data.split())

        # Calculate simple interest
        result = calculate_simple_interest(principal, rate, time)

        # Send the result back to the client
        client_socket.send(str(result).encode('utf-8'))

        # Close the client socket
        client_socket.close()

if __name__ == "__main__":
    main()
