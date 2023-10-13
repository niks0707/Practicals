import socket

# Main client function
def main():
    # Create a socket and connect to the server
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = 'localhost'
    port = 12345
    client_socket.connect((host, port))

    print("Simple Interest Calculation")

    principal = float(input("Enter the principal amount: "))
    rate = float(input("Enter the rate of interest: "))
    time = float(input("Enter the time period (in years): "))

    # Send the principal, rate, and time to the server
    data = "{} {} {}".format(principal, rate, time)
    client_socket.send(data.encode('utf-8'))

    # Receive and print the result from the server
    result = client_socket.recv(1024).decode('utf-8')
    print("Simple Interest Result: {}".format(result))

    # Close the client socket
    client_socket.close()

if __name__ == "__main__":
    main()
