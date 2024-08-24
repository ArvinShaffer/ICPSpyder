#ifndef MYSPIDER_H
#define MYSPIDER_H
#include <memory>
using namespace std;

class MySpider
{
public:
    virtual void Crawl() = 0;
};

class MySpiderFactory
{
public:
    virtual shared_ptr<MySpider> CreateMySpider() = 0;
};

#endif // MYSPIDER_H
