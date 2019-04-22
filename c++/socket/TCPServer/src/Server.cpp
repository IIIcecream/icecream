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

    char msgBuf[] = "Hello, I'm Server.\n";

    while (true)
    {
        clientSock = accept(serverSocket, (sockaddr*)&clientAddr, &nClientAddrLen);
        if (INVALID_SOCKET == clientSock)
            cout << "���ܵ���Ч�ͻ���socket..." << endl;

        cout << "�¿ͻ��˼��룺IP = " << inet_ntoa(clientAddr.sin_addr) << endl;

        // 5 ��ͻ��˷���һ������send
        // ���� + 1 ��Ϊ�˰�bug���\0Ҳ���͹�ȥ
        send(clientSock, msgBuf, strlen(msgBuf) + 1, 0);
    }

	// 6 �ر��׽���closeSocket
    closesocket(serverSocket);

	// ���windows socket����
	WSACleanup();

    return 0;
}