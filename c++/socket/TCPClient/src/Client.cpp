#include <winsock2.h>
#include <iostream>
using namespace std;

int main()
{
    // ����windows socket 2.2����
    WORD ver = MAKEWORD(2, 2);
    WSADATA data;
    WSAStartup(ver, &data);

    // ��socketAPI��������TCP�ͻ���
    // 1 ����һ��socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == clientSocket)
        cout << "����socketʧ��..." << endl;
    else
        cout << "����socket�ɹ�..." << endl;

    // 2 ���ӽ��շ����connect
    sockaddr_in _sin = {};
    _sin.sin_family = AF_INET;
    _sin.sin_port = htons(4567);
    _sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    if (SOCKET_ERROR == connect(clientSocket, (sockaddr*)&_sin, sizeof(_sin)))
        cout << "���ӷ�����ʧ��..." << endl;
    else
        cout << "���ӷ������ɹ�..." << endl;

    // 3 ��������
    char cmdBuf[128];
    while (true)
    {
        cin >> cmdBuf;
        if (0 == strcmp(cmdBuf, "exit"))
        {
            cout << "�յ�exit����������" << endl;
            break;
        }
        else
        {
            send(clientSocket, cmdBuf, strlen(cmdBuf) + 1, 0);
        }

        // 4 ���շ���˷�������recv
        char recvBuf[128] = {};
        int nLen = recv(clientSocket, recvBuf, 128, 0);
        if (nLen > 0)
            cout << "���յ����ݣ�" << recvBuf << endl;
        else
            cout << "���շ���������ʧ��" << endl;
    }

    // 5 �ر��׽���closeSocket
    closesocket(clientSocket);

    // ���windows socket����
    WSACleanup();

    cout << "���˳�" << endl;
    system("pause");
    return 0;
}