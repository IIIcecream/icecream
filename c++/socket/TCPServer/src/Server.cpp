#include <winsock2.h>
#include <iostream>
using namespace std;

int main()
{
	// ����windows socket 2.2����
	WORD ver = MAKEWORD(2, 2);
	WSADATA data;
	WSAStartup(ver, &data);

	// ��socketAPI��������TCP�����
	// 1 ����һ��socket
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (INVALID_SOCKET == serverSocket)
        cout << "����socketʧ��..." << endl;
    else
        cout << "����socket�ɹ�..." << endl;

	// 2 �����ڽ��տͻ������ӵ�����˿�bind
    sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);//host to net usingned short������������������short�ֽ�����һ������
    _sin.sin_addr.S_un.S_addr = INADDR_ANY;// inet_addr("127.0.0.1");
    if (SOCKET_ERROR == bind(serverSocket, (sockaddr*)&_sin, sizeof(_sin)))
        cout << "�󶨶˿�ʧ��..." << endl;
    else
        cout << "�󶨶˿ڳɹ�..." << endl;
	
    // 3 ��������˿�listen
    if (SOCKET_ERROR == listen(serverSocket, 5))
        cout << "�����˿�ʧ��..." << endl;
    else
        cout << "�����˿ڳɹ�..." << endl;

	// 4 �ȴ����տͻ�������accept
    sockaddr_in clientAddr;
    int nClientAddrLen = sizeof(clientAddr);
    SOCKET clientSock = INVALID_SOCKET;

    clientSock = accept(serverSocket, (sockaddr*)&clientAddr, &nClientAddrLen);
    if (INVALID_SOCKET == clientSock)
        cout << "���ܵ���Ч�ͻ���socket..." << endl;
    cout << "�¿ͻ��˼��룺IP = " << inet_ntoa(clientAddr.sin_addr) << endl;
    
    char recvBuf[128] = {};
    while (true)
    {
        // 5 ���տͻ�������
        int nLen = recv(clientSock, recvBuf, 128, 0);
        if (nLen <= 0)
        {
            cout << "�ͻ������˳����������..." << endl;
            break;
        }
        else
        {
            cout << "�յ��ͻ�������" << recvBuf << endl;
        }
       
        // 6 �������󣬲���������
        const char *msgBuf;
        if (0 == strcmp(recvBuf, "getName"))
        {
            msgBuf = "Icecream";
        }
        else if (0 == strcmp(recvBuf, "getAge"))
        {
            msgBuf = "80";
        }
        else
        {
            msgBuf = "???";
        }
        // ���� + 1 ��Ϊ�˰�bug���\0Ҳ���͹�ȥ
        send(clientSock, msgBuf, strlen(msgBuf) + 1, 0);
    }

	// 7 �ر��׽���closeSocket
    closesocket(serverSocket);

	// ���windows socket����
	WSACleanup();

    cout << "���������˳�" << endl;
    system("pause");
    return 0;
}