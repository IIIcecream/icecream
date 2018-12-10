#include "TCPClient.h"

int main()
{
    TCPClient *pSocket = new TCPClient();
    pSocket->initSocket();
    bool bRes = pSocket->doCommunication();
    free(pSocket);

    system("pause");
    return 0;
}