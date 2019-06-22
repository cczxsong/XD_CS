// client.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
client.cpp
author@cczxsong 16030120046 王松
*/
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <windows.h> 
using namespace std;
#pragma comment(lib, "WS2_32.lib") 
int main()
{
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2, 2);
	SOCKET sock = 0;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		cout << "initlization failed!" << endl;
		exit(0);
	}
	sock = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		cout << "failed socket!" << endl;
		return 0;
	}
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(4567);
	sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (connect(sock, (sockaddr*)&sin, sizeof(sockaddr)) == -1)
	{
		cout << "connect failed!" << endl;
		return 0;
	}
	char buffer[256] = "\0";
	int nRecv = 0;
	nRecv = recv(sock, buffer, 256, 0);
	if (nRecv > 0)
	{
		buffer[nRecv] = '\0';
		cout << "reveive data: " << buffer << endl;
	}
	closesocket(sock);
	WSACleanup();
	system("pause");
}