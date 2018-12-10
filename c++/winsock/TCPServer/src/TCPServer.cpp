#include "TCPServer.h"
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

#define BUF_SIZE 64 //buffer_size
#pragma comment(lib, "WS2_32.lib")

void TCPServer::initSocket()
{
    createSocket();
    createListenSocket();
    setSocketAdress();
    bindSocketServer();
    listenSocket();
    waitClient();
}

bool TCPServer::doCommunication()
{
    char buf[BUF_SIZE];
    while (true)
    {
        ZeroMemory(buf, BUF_SIZE);
        int nRetVal = recv(m_oClient, buf, BUFSIZ, 0);
        if (SOCKET_ERROR == nRetVal)
        {
            printf("recv faild\n");
            freeResource();
            return false;
        }

        //��ȡ��ǰϵͳʱ��
        SYSTEMTIME st;
        GetLocalTime(&st);
        char sDateTime[30];
        sprintf(sDateTime, "%4d-%2d-%2d %2d:%2d:%2d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
        //��ӡ�����Ϣ
        printf("%s, Recv From Client [%s:%d] :%s\n", sDateTime, inet_ntoa(m_oAddrClient.sin_addr), m_oAddrClient.sin_port, buf);
        //����ͻ��˷���quit ��������˳�
        if (strcmp(buf, "quit") == 0)
        {
            nRetVal = send(m_oClient, "quit", strlen("quit"), 0);
            break;
        }
        else
        {
            char msg[BUF_SIZE];
            //sprintf(msg, "Message received - %s", buf);
            string s;
            getline(cin, s);
            {
                strcpy(msg, s.c_str());
                //��ͻ��˷��ͻ����ַ���
                nRetVal = send(m_oClient, msg, strlen(msg), 0);
                if (SOCKET_ERROR == nRetVal)
                {
                    printf("send faild\n");
                    freeResource();
                    return false;
                }
            }
        }
    }

    freeResource();
    return true;
}

//��ʼ������
bool TCPServer::createSocket()
{
    if (WSAStartup(MAKEWORD(2, 2), &m_oWSD))
    {
        printf("create socket faild\n");
        return false;
    }
    return true;
}

//�������ڼ�����socket
bool TCPServer::createListenSocket()
{
    m_oServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (INVALID_SOCKET == m_oServer)
    {
        printf("create listen faild\n");
        WSACleanup();
        return false;
    }
    return true;
}

//���÷�����socket��ַ
void TCPServer::setSocketAdress()
{
    m_oAddrServ.sin_family = AF_INET;
    m_oAddrServ.sin_port = htons(9990);
    m_oAddrServ.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
}

//��socket server�����ص�ַ
bool TCPServer::bindSocketServer()
{
    int nRetVal = bind(m_oServer, (const struct sockaddr*)&m_oAddrServ, sizeof(sockaddr_in));
    if (SOCKET_ERROR == nRetVal)
    {
        printf("bind faild\n");
        closesocket(m_oServer);
        WSACleanup();
        return false;
    }
    return true;
}

//��socket server�Ͻ��м���
bool TCPServer::listenSocket()
{
    int nRetVal = listen(m_oServer, 1);
    if (SOCKET_ERROR == nRetVal)
    {
        printf("listen faild");
        closesocket(m_oServer);
        WSACleanup();
        return false;
    }
    return true;
}

//�������Կͻ��˵�����
bool TCPServer::waitClient()
{
    printf("TCP Server start...\n");

    int nAddrClientLen = sizeof(m_oAddrClient);
    m_oClient = accept(m_oServer, (sockaddr FAR*)&m_oAddrClient, &nAddrClientLen);
    if (INVALID_SOCKET == m_oClient)
    {
        printf("accept faild\n");
        closesocket(m_oServer);
        WSACleanup();
        return false;
    }
    return true;
}

//�ͷ���Դ
void TCPServer::freeResource()
{
    closesocket(m_oServer);
    closesocket(m_oClient);
    WSACleanup();
}
