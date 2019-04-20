#include <winsock.h>

#include <iostream>
using namespace std;

int main()
{
	// 启动windows socket 2.2环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA data;
	WSAStartup(ver, &data);

	//////////////////////////////////////////////////////////////////////////
	// 用socketAPI建立简易TCP客户端
	// 1 建立一个socket

	// 2 链接服务器connect
	// 3 接收服务器recv
	// 4 关闭套接字closesocket



	// 清除windows socket环境
	WSACleanup();

	return 0;
}