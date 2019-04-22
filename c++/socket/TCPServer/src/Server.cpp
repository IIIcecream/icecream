#include <winsock2.h>
#include <iostream>
using namespace std;

int main()
{
	// 启动windows socket 2.2环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA data;
	WSAStartup(ver, &data);

	// 用socketAPI建立简易TCP服务端
	// 1 建立一个socket
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (INVALID_SOCKET == serverSocket)
        cout << "创建socket失败..." << endl;
    else
        cout << "创建socket成功..." << endl;

	// 2 绑定用于接收客户端连接的网络端口bind
    sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);//host to net usingned short，处理主机与网络中short字节数不一致问题
    _sin.sin_addr.S_un.S_addr = INADDR_ANY;// inet_addr("127.0.0.1");
    if (SOCKET_ERROR == bind(serverSocket, (sockaddr*)&_sin, sizeof(_sin)))
        cout << "绑定端口失败..." << endl;
    else
        cout << "绑定端口成功..." << endl;
	
    // 3 监听网络端口listen
    if (SOCKET_ERROR == listen(serverSocket, 5))
        cout << "监听端口失败..." << endl;
    else
        cout << "监听端口成功..." << endl;

	// 4 等待接收客户端连接accept
    sockaddr_in clientAddr;
    int nClientAddrLen = sizeof(clientAddr);
    SOCKET clientSock = INVALID_SOCKET;

    char msgBuf[] = "Hello, I'm Server.\n";

    while (true)
    {
        clientSock = accept(serverSocket, (sockaddr*)&clientAddr, &nClientAddrLen);
        if (INVALID_SOCKET == clientSock)
            cout << "接受到无效客户端socket..." << endl;

        cout << "新客户端加入：IP = " << inet_ntoa(clientAddr.sin_addr) << endl;

        // 5 向客户端发送一条数据send
        // 长度 + 1 是为了把bug后的\0也发送过去
        send(clientSock, msgBuf, strlen(msgBuf) + 1, 0);
    }

	// 6 关闭套接字closeSocket
    closesocket(serverSocket);

	// 清除windows socket环境
	WSACleanup();

    return 0;
}