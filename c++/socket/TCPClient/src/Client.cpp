#include <winsock2.h>
#include <iostream>
using namespace std;

int main()
{
    // 启动windows socket 2.2环境
    WORD ver = MAKEWORD(2, 2);
    WSADATA data;
    WSAStartup(ver, &data);

    // 用socketAPI建立简易TCP客户端
    // 1 建立一个socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == clientSocket)
        cout << "创建socket失败..." << endl;
    else
        cout << "创建socket成功..." << endl;

    // 2 连接接收服务端connect
    sockaddr_in _sin = {};
    _sin.sin_family = AF_INET;
    _sin.sin_port = htons(4567);
    _sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    if (SOCKET_ERROR == connect(clientSocket, (sockaddr*)&_sin, sizeof(_sin)))
        cout << "连接服务器失败..." << endl;
    else
        cout << "连接服务器成功..." << endl;

    // 3 接收服务端返回数据recv
    char recvBuf[256] = {};
    int nLen = recv(clientSocket, recvBuf, 256, 0);
    if (nLen > 0)
        cout << "接收到数据：" << recvBuf << endl;
    else
        cout << "接收服务器数据失败" << endl;

    // 4 关闭套接字closeSocket
    closesocket(clientSocket);

    // 清除windows socket环境
    WSACleanup();

    system("pause");
    return 0;
}