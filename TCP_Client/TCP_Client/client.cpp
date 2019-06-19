#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#pragma comment(lib, "Ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS


#include<WinSock2.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
#include<string.h>

int main(int argc, char *argv[])
{
	const int DEFAULT_PORT = 5000;
	WORD wVersionRequested;
	WSADATA wsaData;
	int err, iLen;
	const char* ip = "192.168.255.1";
	/*if (argc < 2)
	{
		cout << "Command:TcpEx_Client ServerIP" << endl;
		system("pause");
		return 0;
	}*/

	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		cout << "加载WinSock失败！";
		return 0;
	}

	//创建用于连接的套接字
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
	if (sockClient == INVALID_SOCKET)
	{
		cout << "socket() fail:" << WSAGetLastError() << endl;
		return 0;
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_addr.S_un.S_addr = inet_addr(ip);
	addrSrv.sin_port = htons(DEFAULT_PORT);

	err = connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//请求连接服务器进程
	if (err == INVALID_SOCKET)
	{
		cout << "connect() fail:" << WSAGetLastError() << endl;
		return 0;
	}

	char sendBuf[1024], hostname[100];
	if (gethostname(hostname, 100) != 0)//获取主机名称
		strcpy_s(hostname, "None");
	strcpy_s(sendBuf, hostname);
	strcat_s(sendBuf, "have cnneted to you!");
	err = send(sockClient, sendBuf, strlen(sendBuf) + 1, 0);//发送数据
	if (err == SOCKET_ERROR)
	{
		cout << "send() fail:" << WSAGetLastError() << endl;
		return 0;
	}

	fflush(stdout);
	while (true)
	{
		fflush(stdout);

		char input[1024] = {0};
		std::cout << "客户端-> ";
		scanf("%s", input);
		err = send(sockClient, input, strlen(input) + 1, 0);//发送数据
		if (err == SOCKET_ERROR)
		{
			cout << "send() fail:" << WSAGetLastError() << endl;
			return 0;
		}

		char recvBuf[1024];
		iLen = recv(sockClient, recvBuf, 1024, 0);//接收数据
		if (iLen == 0)
			return 0;
		else if (iLen == SOCKET_ERROR)
		{
			cout << "recv() fail:" << WSAGetLastError() << endl;
			return 0;
		}
		else
		{
			std::cout << "客户端-> ";
			recvBuf[iLen] = '\0';
			fflush(stdout);

			cout << recvBuf << endl;
		}
	}
	

	closesocket(sockClient);//关闭套接字
	WSACleanup();
}