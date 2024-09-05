#include <QCoreApplication>
#include <iostream>
#include "InternetAccess.h"

void Access(const string& web)
{
    RealInterAccess realInternet;
    ProxyAccess proxyAccess(&realInternet);
    try {
        proxyAccess.ConnectTo(web);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
}

void Access2(const string& web)
{
    VirtualProxyAccess proxyAccess;
    try {
        proxyAccess.ConnectTo(web);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
}

void DynamicAccess(const string& web)
{
    DynamicProxyAccess proxyAccess( [](const string& serverHost) {
        RealInterAccess2 realInternet;
        realInternet.ConnectTo(serverHost);
    });
    try {
        proxyAccess.ConnectTo(web);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Access("badidu.com");
    Access("imooc.com");
    Access("qq.com");
    Access("www.bilibili.com");

    DynamicAccess("baidu.com");
    DynamicAccess("imooc.com");
    DynamicAccess("qq.com");
    DynamicAccess("www.bilibili.com");

    Access2("baidu.com");
    Access2("imooc.com");
    Access2("qq.com");
    Access2("www.bilibili.com");

    return a.exec();
}


