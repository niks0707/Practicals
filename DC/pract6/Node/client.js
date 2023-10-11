const net = require('net');
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

const client = new net.Socket();

client.connect(12345, '127.0.0.1', () => {
    console.log('Connected to server');
    rl.setPrompt('You: ');
    rl.prompt();
});

client.on('data', data => {
    console.log('Server:', data.toString());
    rl.prompt();
});

rl.on('line', line => {
    client.write(line);
});

rl.on('close', () => {
    console.log('Connection closed');
    client.end();
});

client.on('close', () => {
    console.log('Disconnected from server');
    process.exit(0);
});










// The client script also uses the net module and readline module to create a user interface for communication.
// The readline module provides a convenient way to read input from the user.
// The client creates a socket using the net.Socket constructor and connects to the server.
// When the connection is established (connect event), the client sets up the readline interface and prompts the user to input messages.
// The data event is triggered when the client receives data from the server. The data is converted to a string and printed to the console.
// The line event is triggered when the user enters a line of text. The client sends this line to the server using the socket's write method.
// The close event is triggered when the user closes the readline interface. The client ends the connection with the server using the socket's end method.
// The close event for the client socket is also handled to gracefully exit the client script when the server disconnects.