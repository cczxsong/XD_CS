// server.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
server.cpp
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
	SOCKET sListen = 0;
	sockaddr_in sin = { 0 };
	sockaddr_in remoteAddr = { 0 };
	char szText[] = "This is Sylvester.";
	int nAddrLen = 0;
	nAddrLen = sizeof(sockaddr_in);
	sin.sin_port = htons(4567);
	sin.sin_family = AF_INET;
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		cout << "initlization failed!" << endl;
		exit(0);
	}
	sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (bind(sListen, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		cout << "bind failed!" << endl;
		return 0;
	}
	if (listen(sListen, 5) == SOCKET_ERROR)
	{
		cout << "listen failed!" << endl;
		return 0;
	}
	SOCKET sClient = INADDR_ANY;
	int num = 0;
	while (true)
	{
		sClient = accept(sListen, (SOCKADDR*)&remoteAddr, &nAddrLen);
		if (sClient == INVALID_SOCKET)
		{
			cout << "accept failed!" << endl;
			continue;
		}
		else {
			num++;
			cout << "NO." << num << " accept successed!" << endl;
		}
		send(sClient, szText, strlen(szText), 0);
		closesocket(sClient);
	}
	closesocket(sListen);
	WSACleanup();
}