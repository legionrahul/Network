🖧 Winsock TCP Server in C++
This project demonstrates a simple TCP server implemented in C++ using the Windows Sockets API (Winsock). The server listens on 127.0.0.1:55555, accepts incoming connections, receives data from clients, and sends back a confirmation message.

📋 Features
Initializes Winsock DLL.

Creates a TCP socket.

Binds the socket to a local IP address and port.

Listens for incoming client connections.

Accepts a client connection.

Receives data from the client.

Sends a confirmation message back to the client.



🛠️ Prerequisites
Windows operating system.

C++ compiler (e.g., MSVC, MinGW).

Basic understanding of socket programming.
wired.com
+8
makeareadme.com
+8
github.com
+8

🚀 Getting Started
1. Clone the Repository
bash
Copy
Edit
git clone https://github.com/legionrahul/Network.git
cd Network
2. Compile the Code
Use your preferred C++ compiler to compile the source code. For example, with MSVC:

vbnet
Copy
Edit
cl /EHsc server.cpp ws2_32.lib
3. Run the Server
pgsql
Copy
Edit
server.exe
The server will start and listen on 127.0.0.1:55555.

📄 Code Overview
The main steps in the server.cpp file are:

Initialize Winsock.

Create a socket.

Bind the socket to an IP address and port.

Listen for incoming connections.

Accept a client connection.

Receive data from the client.

Send a confirmation message to the client.

Clean up and close sockets.

🧪 Testing
You can test the server using a simple TCP client or tools like telnet:

nginx
Copy
Edit
telnet 127.0.0.1 55555
Type a message and press Enter. The server should display the received message and send back a confirmation.

📚 Resources
Winsock Programming Tutorial

Beej's Guide to Network Programming

📄 License
This project is licensed under the MIT License - see the LICENSE file for details.
