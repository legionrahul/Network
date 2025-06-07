#include <iostream>
#include <winsock2.h>

#include <ws2tcpip.h>//for winsocket
#include<tchar.h>
int main(int argc, char** argv[])
{
	std::cout << "<------------------------first step----------setup dll----------------------->\n";
	SOCKET serverSocket, acceptSocket;
	int port = 55555;
	WSADATA wsaData;
	int wsaErr;
	WORD wVersionRequested = MAKEWORD(2, 2);
	wsaErr = WSAStartup(wVersionRequested, &wsaData);
	if(wsaErr)
	{
		std::cout << "winsock dll not found\n";
	}
	else {
		std::cout << "winsock dll found\n";
		std::cout <<"status: "<<wsaData.szSystemStatus << "\n";
	}
	std::cout << "<------------------------second step--------setup socket------------------------->\n";


	serverSocket = -1;//INVALID_SOCKET
	serverSocket = socket(AF_INET/*2:internetwork udp,tcp*/, SOCK_STREAM, IPPROTO_TCP);//we can also use number inplace of name ...
	if (!serverSocket)
	{
		std::cout << "error at socket:" << WSAGetLastError() << "\n";
	}
	else {
		std::cout << "socket is ok\n";

	}

	std::cout << "-----------------3 step -------bind--------------\n";
	
	
	sockaddr_in service;
	service.sin_family = AF_INET;//2 is also used in place of name 
	InetPton(AF_INET,_T("127.0.0.1"), &service.sin_addr.s_addr);
	service.sin_port = htons(port);
	int bindResult=bind(serverSocket, (SOCKADDR*)&service, sizeof(service));
	if (bindResult == SOCKET_ERROR) 
	{
		std::cout << "bind failed" << WSAGetLastError() << std::endl;
		closesocket(serverSocket);
		WSACleanup();
	}
	else {
		std::cout << "bind success" <<std::endl;
	}
	std::cout << "--------step 4 ______________listen________" << std::endl;
	int listenResult = -1;
	listenResult = listen(serverSocket, 1);
	if(listenResult==SOCKET_ERROR)
		{
			std::cout<<"error on listen socket"<<WSAGetLastError()<<std::endl;
	}
	else {
		std::cout << "listening..." << std::endl;
	}
	std::cout << "-------step 5------------------accept---------------" << std::endl;

	acceptSocket = accept(serverSocket, NULL, NULL);
	if(acceptSocket==INVALID_SOCKET)
		{
		std::cout << "Accept failed" << WSAGetLastError() << std::endl;
		WSACleanup();
		return -1;
	}
	else
	{
		std::cout << "<-----------step 6---------Recieve data--------->" << std::endl;
		char buffer[200] = "";
		int byteCount = recv(acceptSocket, buffer, 200, 0);
		int size = 1;
		for (int i = 0; i < 200; i++)
		{
			while (buffer[i] != '\0')
			{
				size++;
				i++;
			}
		}
		if (byteCount < 0)
		{
			std::cout << "error in recieve data" << WSAGetLastError() << std::endl;
			return 0;
		}
		else
		{
			std::cout <<"Data Received is:"<< buffer << std::endl;
			std::cout << "size of data received:" << size << std::endl;
		}
		


		std::cout << "accept success" << std::endl;

		std::cout << "step 6 --Sending confirmation---->" << std::endl;
		char confirmation[200] = "";
		
		int sendByte = send(acceptSocket,confirmation, 200, 0);
		if (sendByte > 0)
		{
			std::cout << "automated message sent" << std::endl;
		}else
		{
			WSACleanup();


		}

		system("pause");
		WSACleanup();

	}
	

}