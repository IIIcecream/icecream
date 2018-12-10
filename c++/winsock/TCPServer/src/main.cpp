#include "TCPServer.h"

int main()
{
    TCPServer *pSocket = new TCPServer();
    pSocket->initSocket();
    bool bRes = pSocket->doCommunication();
    free(pSocket);

    system("pause");
    return 0;
}