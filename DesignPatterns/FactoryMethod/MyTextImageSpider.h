#ifndef MYTEXTIMAGESPIDER_H
#define MYTEXTIMAGESPIDER_H
#include "MySpider.h"
#include <iostream>
using namespace std;

class MyTextImageSpider : public MySpider
{
public:
    virtual void Crawl()
    {
        cout << "MyTextImageSpider::Crawl" << endl;
    }
};

class MyTextImageSpiderFactory : public MySpiderFactory
{
public:
    virtual shared_ptr<MySpider> CreateMySpider()
    {
        return make_shared<MyTextImageSpider>();
    }
};

#endif // MYTEXTIMAGESPIDER_H
