import socket

# Define the server's host and port
HOST = 'localhost'
PORT = 12345

# Create a socket for the client
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((HOST, PORT))

print("Options:")
print("1. Compare two strings")
print("2. Count characters in a string")

choice = input("Enter your choice: ")

if choice == "1":
    str1 = input("Enter the first string: ")
    str2 = input("Enter the second string: ")
    client_socket.send(f"compare {str1} {str2}".encode('utf-8'))
    result = client_socket.recv(1024).decode('utf-8')
    print(f"Result of comparison: {result}")

elif choice == "2":
    str_to_count = input("Enter the string to count characters: ")
    client_socket.send(f"count {str_to_count}".encode('utf-8'))
    result = client_socket.recv(1024).decode('utf-8')
    print(f"Character count: {result}")

else:
    print("Invalid Choice.")

# Close the client socket
client_socket.close()
