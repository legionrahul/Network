#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include<tchar.h>

int main()
{
	std::cout << "Step1:->Setup dll:->" << std::endl;
	SOCKET clientSocket;
	WSADATA wsaData;//its a dataStructure
	int port=55555;
	WORD wVersionRequested = MAKEWORD(2, 2);
	int dllResult=WSAStartup(wVersionRequested, &wsaData);
	if (dllResult == 1)//everything is true except  0
	{
		std::cout << "dll setup failed" << WSAGetLastError() << std::endl;
		WSACleanup();
	}
	else {
		std::cout << "dll setup success" << std::endl;

	}
	std::cout << "Step2:->CREATE SOCKET:->" << std::endl;
	clientSocket = INVALID_SOCKET;
	clientSocket = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);//(internetwork,streamsocket,protocol) return 0 if everything is ok
	if (clientSocket == INVALID_SOCKET)
	{
		std::cout << "error in socket " << WSAGetLastError() << std::endl;
		WSACleanup();
	}
	else
	{
		std::cout << "socket success:" << std::endl;

	}

	std::cout << "STEP3:->CONNECT" << std::endl;


	sockaddr_in clientService;
	
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);
	int connectResult = connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService));
	if (connectResult != 0)//SOCKET_ERROR is also valid...
	{
		std::cout << "connection error" << std::endl;
		WSACleanup();
		return 0;
	}
	else
	{
		std::cout << "client connect():ok" << std::endl;
		std::cout << "connect to server ..." << std::endl;
		std::cout << "<STEP4:->SEND TCP DATA:->" << std::endl;

		char buffer[200] = "";
		//std::cin >> buffer;
		std::cout << "enter your message here:";
		std::cin.getline(buffer, 200);//for continues reading buffer with whitespace characters
		int byteCount = send(clientSocket, buffer, 200, 0);//(SOCKET,message,message_size,flags[optional])
		  
		//for counting number of bytes sent....
		int size=1;
	   for (int i = 0; i < 200; i++)
	   {
		   while (buffer[i] != '\0')
		   {
			   size++;
			    i++;
		   }
	   }

		if (byteCount == SOCKET_ERROR)
		{
			std::cout << "Error in sending data" << WSAGetLastError() << std::endl;
			// WSACleanup();
			return -1;

		}
		else
		{  
			 
			std::cout << "success data sent!" << std::endl;
			std::cout << "number of byte sent: "<<size << std::endl;

		}
		std::cout << " confirmation recieved" << std::endl;
		    char recieveBuffer[200] = "";
			int recieveByte = recv(clientSocket, recieveBuffer, 200, 0);
			if (recieveByte > 0)
			{
				std::cout << recieveBuffer << std::endl;
			}
			else
			{
				WSACleanup();
			}
		system("pause");
		WSACleanup();
		return 0;
	}

		

}














