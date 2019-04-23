#include <winsock2.h>
#include <iostream>
using namespace std;

// 命令类型
enum CMD
{
    eCMD_LOGIN,
    eCMD_LOGOUT,
    eCMD_ERROR
};

// 消息头
struct DataHeader
{
    short dataLength;   // 数据长度
    CMD cmd;  //命令
};

struct Login
{
    char sUserName[32];
    char sPassword[32];
};

struct LoginResult
{
    int result;
};

struct Logout
{
    char sUserName[32];
};

struct LogoutResult
{
    int result;
};

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

    clientSock = accept(serverSocket, (sockaddr*)&clientAddr, &nClientAddrLen);
    if (INVALID_SOCKET == clientSock)
        cout << "接受到无效客户端socket..." << endl;
    cout << "新客户端加入：IP = " << inet_ntoa(clientAddr.sin_addr) << endl;
    
    while (true)
    {
        // 5 接收客户端数据
        DataHeader dataHeader;
        int nLen = recv(clientSock, (char *)&dataHeader, sizeof(DataHeader), 0);
        if (nLen <= 0)
        {
            cout << "客户端已退出，任务结束..." << endl;
            break;
        }
        cout << "收到命令：" << dataHeader.cmd << "数据长度" << dataHeader.dataLength << endl;
       
        switch (dataHeader.cmd)
        {
        case eCMD_LOGIN:
        {
            Login login;

            recv(clientSock, (char *)&login, sizeof(Login), 0);
            // 忽略判断用户名密码的校验

            cout << login.sUserName << " is login " << endl;

            DataHeader loginResultHeader = { sizeof(LoginResult) , eCMD_LOGIN };
            send(clientSock, (const char*)&loginResultHeader, sizeof(DataHeader), 0);
            LoginResult loginResult = { 1 };
            send(clientSock, (const char*)&loginResult, sizeof(LoginResult), 0);
            
            break;
        }
        case eCMD_LOGOUT:
        {
            Logout logout;

            recv(clientSock, (char *)&logout, sizeof(Logout), 0);
            // 忽略判断用户名密码的校验

            cout << logout.sUserName << " is logout " << endl;

            DataHeader loginResultHeader = { sizeof(LogoutResult) , eCMD_LOGOUT };
            send(clientSock, (const char*)&loginResultHeader, sizeof(DataHeader), 0);
            LogoutResult loginResult = { 1 };
            send(clientSock, (const char*)&loginResult, sizeof(LogoutResult), 0);
            break;
        }
        default:
        {
            DataHeader errHeader;
            errHeader.cmd = eCMD_ERROR;
            errHeader.dataLength = 0;
            send(clientSock, (const char*)&errHeader, sizeof(DataHeader), 0);
        }
        }
    }

	// 7 关闭套接字closeSocket
    closesocket(serverSocket);

	// 清除windows socket环境
	WSACleanup();

    cout << "服务器已退出" << endl;
    system("pause");
    return 0;
}