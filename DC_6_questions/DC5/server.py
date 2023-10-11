import socket
import math
import sys

# Function to calculate the square root of a number
def calculate_sqrt(number):
    return math.sqrt(number)

# Function to calculate the square of a number
def calculate_square(number):
    return number ** 2

# Function to calculate the factorial of a number
def calculate_factorial(number):
    if number == 0:
        return 1
    return number * calculate_factorial(number - 1)

# Main server function
def main():
    # Create a socket and bind it to a specific host and port
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = 'localhost'
    port = 12345
    server_socket.bind((host, port))

    # Listen for incoming connections
    server_socket.listen(5)
    print("Server is listening on {}:{}".format(host, port))

    while True:
        # Accept a client connection
        client_socket, addr = server_socket.accept()
        print("Accepted connection from {}:{}".format(addr[0], addr[1]))

        # Receive the operation and number from the client
        data = client_socket.recv(1024).decode('utf-8')
        if data == '':
            print("Disconnected - from {}:{}".format(addr[0], addr[1]))
            continue
        operation, number = data.split()
        number = float(number)

        # Perform the requested mathematical operation
        if operation == 'sqrt' or operation == '1':
            result = calculate_sqrt(number)
        elif operation == 'square' or operation == '2':
            result = calculate_square(number)
        elif operation == 'factorial' or operation == '3':
            result = calculate_factorial(int(number))
        else:
            result = "Invalid operation"

        # Send the result back to the client
        client_socket.send(str(result).encode('utf-8'))

        # Close the client socket
        client_socket.close()

if __name__ == "__main__":
    main()
