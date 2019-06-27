#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")

//#include <thread>
#include <WinSock2.h>
#include <iostream>
#include <string.h>
#include <Windows.h>

using namespace std;

DWORD WINAPI FaSong(LPVOID lpParamter, SOCKET& sockConn) {
	while (1) {
		int iLen;
		char recvBuf[1024] = "\0";
		iLen = recv(sockConn, recvBuf, 1024, 0);//接收数据
		if (iLen == SOCKET_ERROR)
		{
			cout << "recv() fail:" << WSAGetLastError() << endl;
			break;
		}

		recvBuf[iLen] = '\0';
		cout << "服务器-> " << recvBuf << endl;
	}

	return 0L;
}
DWORD WINAPI JieShou(LPVOID lpParamter, SOCKET& sockConn) {
	int err;
	while (1) {
		char sendt[1024] = { 0 };
		std::cout << "客户端-> ";
		scanf("%s", &sendt);
		///strcpy(sendt, recvBuf);
		err = send(sockConn, (const char*)&sendt, strlen(sendt) + 1, 0);//发送数据
		if (err == SOCKET_ERROR)
		{
			cout << "send() fail:" << WSAGetLastError() << endl;
			break;
		}
	}

	return 0L;
}

int main(int argc, char *argv[])
{
	const int DEFAULT_PORT = 5000;
	WORD wVersionRequested;
	WSADATA wsaData;
	int err, iLen;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		cout << "加载WinSock失败！";
		return 0;
	}

	//创建用于侦听的套接字
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);//创建服务器监听套接字
	if (sockSrv == INVALID_SOCKET)
	{
		cout << "socket() fail:" << WSAGetLastError() << endl;
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//自动分配地址，字节顺序转换
	addrSrv.sin_port = htons(DEFAULT_PORT);//字节顺序转换

	//绑定本地主机IP和端口
	err = bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	if (err != 0)
	{
		cout << "bind() fail:" << WSAGetLastError() << endl;
		return 0;
	}

	//bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	//监听
	err = listen(sockSrv, 5);
	if (err != 0)
	{
		cout << "listen() fail:" << WSAGetLastError() << endl;
		return 0;
	}

	cout << "Server waiting...:" << endl;

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

	while (1)
	{
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);//接受客户机进程连接请求
		if (sockConn == INVALID_SOCKET)
		{
			cout << "accept() fail:" << WSAGetLastError() << endl;
			break;
		}

		//char sendBuf[1024], hostname[100];
		//if (gethostname(hostname, 100) != 0)//获取主机名称
		//	strcpy_s(hostname, "None");
		//sprintf_s(sendBuf, "welcome %s connected to %s!", inet_ntoa(addrClient.sin_addr), hostname);

		//err = send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);//发送数据
		//if (err == SOCKET_ERROR)
		//{
		//	cout << "send() fail:" << WSAGetLastError() << endl;
		//	break;
		//}
		//std::cout << flush;
		while (1)
		{
			//std::FS(FaSong);
			HANDLE FS = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)FaSong(NULL, sockConn), NULL, 0, NULL);

			//char recvBuf[1024] = "\0";
			//iLen = recv(sockConn, recvBuf, 1024, 0);//接收数据
			//if (iLen == SOCKET_ERROR)
			//{
			//	cout << "recv() fail:" << WSAGetLastError() << endl;
			//	break;
			//}

			//recvBuf[iLen] = '\0';
			//cout  << "服务器-> " << recvBuf << endl;
			//char sendt[1024] = {0};
			//std::cout << "客户端-> ";
			//scanf("%s", &sendt);
			/////strcpy(sendt, recvBuf);
			//err = send(sockConn, (const char*)&sendt, strlen(sendt) + 1, 0);//发送数据
			//if (err == SOCKET_ERROR)
			//{
			//	cout << "send() fail:" << WSAGetLastError() << endl;
			//	break;
			//}

			HANDLE JS = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)JieShou(NULL, sockConn), NULL, 0, NULL);
			CloseHandle(FS);
			CloseHandle(JS);
		}

		closesocket(sockConn);//关闭套接字
	}

	closesocket(sockSrv);//关闭服务器侦听套接字
	WSACleanup();

	return 0;
}