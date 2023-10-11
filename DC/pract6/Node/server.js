const net = require('net');

const server = net.createServer(socket => {
    console.log('Client connected:', socket.remoteAddress, socket.remotePort);

    socket.on('data', data => {
        const message = data.toString().trim();
        console.log('Received from client:', message);
        const response = generateResponse(message);
        socket.write(response);
    });

    socket.on('end', () => {
        console.log('Client disconnected:', socket.remoteAddress, socket.remotePort);
    });
});

const PORT = 12345;
server.listen(PORT, () => {
    console.log(`Server listening on port ${PORT}`);
});


function generateResponse(inputMessage) {
    const responses = {
        hi: "Hello! How can I assist you?",
        hello: "Hello! How can I assist you?",
        "how are you": "I'm just a server, but I'm here to help!",
        bye: "Goodbye! Have a great day!",
        "": "I'm here to chat. Say something!"
    };
    const response = responses[inputMessage.toLowerCase()] || "I'm not sure how to respond to that.";
    return response + '\n';
}










// The server script sets up a TCP server using the net module.
// When a client connects to the server, the createServer callback function is called, and a socket object is created to represent the connection to that specific client.
// The data event is triggered when the server receives data from the client. The received data is converted to a string and trimmed to remove any whitespace.
// The generateResponse function generates a response based on the received message using predefined responses in the responses object. It converts the input message to lowercase to handle variations in case.
// The server sends the generated response back to the client using the socket's write method.
// The end event is triggered when the client disconnects, allowing the server to log the disconnection.