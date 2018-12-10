#pragma once
#include <winsock2.h>

class TCPClient
{
public:
    TCPClient() {}
    ~TCPClient() {}
    void initSocket();
    bool doCommunication();

private:
    bool createSocket();
    bool createCommunicationSocket();
    void setSocketAdress();
    bool connnetServer();
    void freeResource();

private:
    WSADATA m_oWSD;
    SOCKET m_oHost;
    SOCKADDR_IN m_oAddrServ;
};