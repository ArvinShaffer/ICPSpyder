#include <QCoreApplication>
#include "MyICPSpyder.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyICPSpyder ms;
    ms.GetInfo("www.baidu.com");

    return a.exec();
}
