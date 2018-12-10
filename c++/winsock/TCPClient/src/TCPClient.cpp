#include "TCPClient.h"
#include <String>
#include <iostream>
using namespace std;

#pragma comment(lib, "WS2_32.lib")

#define BUF_SIZE 64

void TCPClient::initSocket()
{
    createSocket();
    createCommunicationSocket();
    setSocketAdress();
    connnetServer();
}

bool TCPClient::doCommunication()
{
    char buf[BUF_SIZE];
    string str;
    //循环向服务器发送字符串，并显示反馈信息
    //发送quit将使服务器程序退出，同事客户端程序自身也将退出
    while (true)
    {
        //向服务器发送数据
        cout << "Please input a string to send: ";
        //接受输入的数据
        getline(cin, str);
        //将用户输入的数据复制到bug中
        ZeroMemory(buf, BUF_SIZE);
        strcpy(buf, str.c_str());
        //向服务器发送数据
        int nRetVal = send(m_oHost, buf, strlen(buf), 0);
        if (SOCKET_ERROR == nRetVal)
        {
            cout << "send faild" << endl;
            closesocket(m_oHost);
            WSACleanup();
            return false;
        }
        //接受服务器回传的数据
        nRetVal = recv(m_oHost, buf, sizeof(buf) + 1, 0);
        cout << "Recv From Server: " << buf << endl;
        //如果收到的是quit，则退出
        if (strcmp(buf, "quit") == 0)
        {
            cout << "quit" << endl;
            break;
        }
    }
    freeResource();
    return true;
}

//初始化环境
bool TCPClient::createSocket()
{
    if (WSAStartup(MAKEWORD(2, 2), &m_oWSD))
    {
        cout << "create socket faild" << endl;
        return false;
    }
    return true;
}

//创建用于通信的Socket
bool TCPClient::createCommunicationSocket()
{
    m_oHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (WSAStartup(MAKEWORD(2, 2), &m_oWSD))
    {
        cout << "create communication faild" << endl;
        WSACleanup();
        return false;
    }
    return true;
}

//设置服务器socket地址
void TCPClient::setSocketAdress()
{
    //设置服务器地址
    m_oAddrServ.sin_family = AF_INET;
    m_oAddrServ.sin_addr.S_un.S_addr = inet_addr("10.1.80.22");
    m_oAddrServ.sin_port = htons(9990);
}

//连接到服务器
bool TCPClient::connnetServer()
{
    int nRetVal = connect(m_oHost, (LPSOCKADDR)&m_oAddrServ, sizeof(m_oAddrServ));
    if (SOCKET_ERROR == nRetVal)
    {
        cout << "connect faild" << endl;
        freeResource();
        return false;
    }
    return true;
}

//释放资源
void TCPClient::freeResource()
{
    closesocket(m_oHost);
    WSACleanup();
}

