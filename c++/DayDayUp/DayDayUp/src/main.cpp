#include <iostream>
#include <QApplication>
#include "DDPluginService.h"
#include "DDExportLoad.h"

using namespace std;

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   DDExportLoad ooo;
   ooo.print();

    //DDPluginService *pService = new DDPluginService();
    //cout << pService->print() << endl;

    cout << "Hello World!" << endl;
    return 0;
}