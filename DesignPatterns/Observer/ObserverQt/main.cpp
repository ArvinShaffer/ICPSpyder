#include "MainWindow.h"

#include <QApplication>
#include <QPushButton>
#include "News.h"
#include "Reader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QPushButton btn("Quit");
    //QObject::connect(&btn, SIGNAL(clicked()), &a, SLOT(quit()));
    //btn.show();
    News n("News N");
    Reader r1(1);
    Reader r2(2);
    QObject::connect(&n, SIGNAL(news(QString)), &r1, SLOT(ReceiveInfo(QString)));
    QObject::connect(&n, SIGNAL(news(QString)), &r2, SLOT(ReceiveInfo(QString)));

    n.send();
    return a.exec();
}
