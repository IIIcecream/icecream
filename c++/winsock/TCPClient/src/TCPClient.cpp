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
    //ѭ��������������ַ���������ʾ������Ϣ
    //����quit��ʹ�����������˳���ͬ�¿ͻ��˳�������Ҳ���˳�
    while (true)
    {
        //���������������
        cout << "Please input a string to send: ";
        //�������������
        getline(cin, str);
        //���û���������ݸ��Ƶ�bug��
        ZeroMemory(buf, BUF_SIZE);
        strcpy(buf, str.c_str());
        //���������������
        int nRetVal = send(m_oHost, buf, strlen(buf), 0);
        if (SOCKET_ERROR == nRetVal)
        {
            cout << "send faild" << endl;
            closesocket(m_oHost);
            WSACleanup();
            return false;
        }
        //���ܷ������ش�������
        nRetVal = recv(m_oHost, buf, sizeof(buf) + 1, 0);
        cout << "Recv From Server: " << buf << endl;
        //����յ�����quit�����˳�
        if (strcmp(buf, "quit") == 0)
        {
            cout << "quit" << endl;
            break;
        }
    }
    freeResource();
    return true;
}

//��ʼ������
bool TCPClient::createSocket()
{
    if (WSAStartup(MAKEWORD(2, 2), &m_oWSD))
    {
        cout << "create socket faild" << endl;
        return false;
    }
    return true;
}

//��������ͨ�ŵ�Socket
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

//���÷�����socket��ַ
void TCPClient::setSocketAdress()
{
    //���÷�������ַ
    m_oAddrServ.sin_family = AF_INET;
    m_oAddrServ.sin_addr.S_un.S_addr = inet_addr("10.1.80.22");
    m_oAddrServ.sin_port = htons(9990);
}

//���ӵ�������
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

//�ͷ���Դ
void TCPClient::freeResource()
{
    closesocket(m_oHost);
    WSACleanup();
}

