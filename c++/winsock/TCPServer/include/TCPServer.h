#pragma once
#include <winsock2.h>

class TCPServer
{
public:
    TCPServer() {}
    ~TCPServer() {}
    void initSocket();
    bool doCommunication();

private:
    bool createSocket();
    bool createListenSocket();
    void setSocketAdress();
    bool bindSocketServer();
    bool listenSocket();
    bool waitClient();
    void freeResource();

private:
    WSADATA m_oWSD;
    SOCKET m_oServer;
    SOCKET m_oClient;
    SOCKADDR_IN m_oAddrServ;
    SOCKADDR_IN m_oAddrClient;
};