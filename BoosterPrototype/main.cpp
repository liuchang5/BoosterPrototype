#include "LCMainWidget.h"
#include <QApplication>
#include "LCLog.h"

int main(int argc, char *argv[])
{
    bool bRetCode = false;
    LCLogInit();
    QApplication a(argc, argv);

    LCMainWidget MainWidget;

    do
    {
        bRetCode = MainWidget.Init();
        if (!bRetCode) break;

        MainWidget.show();

        bRetCode = a.exec();
        if (!bRetCode) break;

        bRetCode = MainWidget.Uninit();
        if (!bRetCode) break;

        bRetCode = true;
    }while(0);

    return bRetCode;
}
