#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")

#include<WinSock2.h>
#include<iostream>
using namespace std;
#include<string.h>

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
		cout << "����WinSockʧ�ܣ�";
		return 0;
	}

	//���������������׽���
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);//���������������׽���
	if (sockSrv == INVALID_SOCKET)
	{
		cout << "socket() fail:" << WSAGetLastError() << endl;
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//�Զ������ַ���ֽ�˳��ת��
	addrSrv.sin_port = htons(DEFAULT_PORT);//�ֽ�˳��ת��

	//�󶨱�������IP�Ͷ˿�
	err = bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	if (err != 0)
	{
		cout << "bind() fail:" << WSAGetLastError() << endl;
		return 0;
	}

	//����
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
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);//���ܿͻ���������������
		if (sockConn == INVALID_SOCKET)
		{
			cout << "accept() fail:" << WSAGetLastError() << endl;
			break;
		}
		char sendBuf[1024], hostname[100];
		if (gethostname(hostname, 100) != 0)//��ȡ��������
			strcpy_s(hostname, "None");
		sprintf_s(sendBuf, "welcome %s connected to %s!", inet_ntoa(addrClient.sin_addr), hostname);

		err = send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);//��������
		if (err == SOCKET_ERROR)
		{
			cout << "send() fail:" << WSAGetLastError() << endl;
			break;
		}

		while (1)
		{
			

			char recvBuf[1024] = "\0";
			iLen = recv(sockConn, recvBuf, 1024, 0);//��������
			if (iLen == SOCKET_ERROR)
			{
				cout << "recv() fail:" << WSAGetLastError() << endl;
				break;
			}

			recvBuf[iLen] = '\0';
			cout  << "������-> " << recvBuf << endl;

			char sendt[1024] = {0};
			std::cout << "�ͻ���-> ";
			scanf("%s", &sendt);

			err = send(sockConn, (const char*)&sendt, strlen(sendt) + 1, 0);//��������
			if (err == SOCKET_ERROR)
			{
				cout << "send() fail:" << WSAGetLastError() << endl;
				break;
			}
		}
		
		closesocket(sockConn);//�ر��׽���
	}

	closesocket(sockSrv);//�رշ����������׽���
	WSACleanup();

	return 0;
}