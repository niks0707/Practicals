import socket
import json

# Server configuration
SERVER_HOST = "127.0.0.1"
SERVER_PORT = 12345
LOG_FILE = "server_log.json"

# Dictionary to store client states
client_states = {}

def handle_client(client_socket, address):
    print(f"New connection from {address}")

    while True:
        # Receive data from the client
        data = client_socket.recv(1024).decode('utf-8')
        if not data:
            break

        # Handle client state
        if address not in client_states:
            client_states[address] = []
        client_states[address].append(data)

        # Send back the modified data
        client_socket.send(json.dumps(client_states[address]).encode('utf-8'))

    # Remove client state when the client disconnects
    del client_states[address]
    print(f"Connection from {address} closed")
    client_socket.close()

    # Write server log to JSON file
    with open(LOG_FILE, 'w') as json_file:
        json.dump(client_states, json_file, indent=4)

# Main server function
def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((SERVER_HOST, SERVER_PORT))
    server_socket.listen(5)

    print(f"Server listening on {SERVER_HOST}:{SERVER_PORT}")

    while True:
        client_socket, client_address = server_socket.accept()
        handle_client(client_socket, client_address)

if __name__ == "__main__":
    main()
