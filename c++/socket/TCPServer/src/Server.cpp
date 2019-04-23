#include <winsock2.h>
#include <iostream>
using namespace std;

// ��������
enum CMD
{
    eCMD_LOGIN,
    eCMD_LOGOUT,
    eCMD_ERROR
};

// ��Ϣͷ
struct DataHeader
{
    short dataLength;   // ���ݳ���
    CMD cmd;  //����
};

struct Login
{
    char sUserName[32];
    char sPassword[32];
};

struct LoginResult
{
    int result;
};

struct Logout
{
    char sUserName[32];
};

struct LogoutResult
{
    int result;
};

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
    
    while (true)
    {
        // 5 ���տͻ�������
        DataHeader dataHeader;
        int nLen = recv(clientSock, (char *)&dataHeader, sizeof(DataHeader), 0);
        if (nLen <= 0)
        {
            cout << "�ͻ������˳����������..." << endl;
            break;
        }
        cout << "�յ����" << dataHeader.cmd << "���ݳ���" << dataHeader.dataLength << endl;
       
        switch (dataHeader.cmd)
        {
        case eCMD_LOGIN:
        {
            Login login;

            recv(clientSock, (char *)&login, sizeof(Login), 0);
            // �����ж��û��������У��

            cout << login.sUserName << " is login " << endl;

            DataHeader loginResultHeader = { sizeof(LoginResult) , eCMD_LOGIN };
            send(clientSock, (const char*)&loginResultHeader, sizeof(DataHeader), 0);
            LoginResult loginResult = { 1 };
            send(clientSock, (const char*)&loginResult, sizeof(LoginResult), 0);
            
            break;
        }
        case eCMD_LOGOUT:
        {
            Logout logout;

            recv(clientSock, (char *)&logout, sizeof(Logout), 0);
            // �����ж��û��������У��

            cout << logout.sUserName << " is logout " << endl;

            DataHeader loginResultHeader = { sizeof(LogoutResult) , eCMD_LOGOUT };
            send(clientSock, (const char*)&loginResultHeader, sizeof(DataHeader), 0);
            LogoutResult loginResult = { 1 };
            send(clientSock, (const char*)&loginResult, sizeof(LogoutResult), 0);
            break;
        }
        default:
        {
            DataHeader errHeader;
            errHeader.cmd = eCMD_ERROR;
            errHeader.dataLength = 0;
            send(clientSock, (const char*)&errHeader, sizeof(DataHeader), 0);
        }
        }
    }

	// 7 �ر��׽���closeSocket
    closesocket(serverSocket);

	// ���windows socket����
	WSACleanup();

    cout << "���������˳�" << endl;
    system("pause");
    return 0;
}