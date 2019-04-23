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

    // 用socketAPI建立简易TCP客户端
    // 1 建立一个socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == serverSocket)
        cout << "创建socket失败..." << endl;
    else
        cout << "创建socket成功..." << endl;

    // 2 连接接收服务端connect
    sockaddr_in _sin = {};
    _sin.sin_family = AF_INET;
    _sin.sin_port = htons(4567);
    _sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    if (SOCKET_ERROR == connect(serverSocket, (sockaddr*)&_sin, sizeof(_sin)))
        cout << "连接服务器失败..." << endl;
    else
        cout << "连接服务器成功..." << endl;

    // 3 请求命令
    char cmdBuf[128];
    while (true)
    {
        cin >> cmdBuf;
        if (0 == strcmp(cmdBuf, "exit"))
        {
            cout << "收到exit命令，任务结束" << endl;
            break;
        }
        else if(0 == strcmp(cmdBuf, "login"))
        {
            DataHeader dataHeader = { sizeof(Login), eCMD_LOGIN };
            send(serverSocket, (const char *)&dataHeader, sizeof(DataHeader), 0);

            Login login = {"tangw", "tangwei"};
            send(serverSocket, (const char *)&login, sizeof(Login), 0);

            DataHeader loginResultHeader;
            recv(serverSocket, (char *)&loginResultHeader, sizeof(DataHeader), 0);
            if (loginResultHeader.dataLength == sizeof(LoginResult))
            {
                LoginResult loginResult;
                recv(serverSocket, (char *)&loginResult, sizeof(LoginResult), 0);
                cout << "LoginResult:" << loginResult.result << endl;
            }
            else
                cout << "LoginReuslt is Error" << endl;
        }
        else if (0 == strcmp(cmdBuf, "logout"))
        {
            DataHeader dataHeader = { sizeof(Logout), eCMD_LOGOUT };
            send(serverSocket, (const char *)&dataHeader, sizeof(DataHeader), 0);

            Logout logout = { "tangw" };
            send(serverSocket, (const char *)&logout, sizeof(Logout), 0);

            DataHeader logoutResultHeader;
            recv(serverSocket, (char *)&logoutResultHeader, sizeof(DataHeader), 0);
            if (logoutResultHeader.dataLength == sizeof(LogoutResult))
            {
                LogoutResult logoutResult;
                recv(serverSocket, (char *)&logoutResult, sizeof(LogoutResult), 0);
                cout << "LogoutResult:" << logoutResult.result << endl;
            }
            else
                cout << "LogoutResult is Error" << endl;
        }
        else
        {
            cout << "不支持的命令，请重新输入" << endl;
        }
    }

    // 5 关闭套接字closeSocket
    closesocket(serverSocket);

    // 清除windows socket环境
    WSACleanup();

    cout << "已退出" << endl;
    system("pause");
    return 0;
}