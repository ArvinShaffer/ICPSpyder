#include <QCoreApplication>
#include <iostream>
using namespace std;
#include "MyTextImageSpider.h"
#include "MyPrototype.h"

enum class SPIDERTYPE
{
    TEXT,
    IMAGE,
    VIDEO
};

class Spider
{
public:
    virtual void Crawl() = 0;
};


class TextSpider : public Spider
{
public:
    virtual void Crawl()
    {
        cout << "TextSpider::Crawl" << endl;
    }
};

class ImageSpider : public Spider
{
public:
    virtual void Crawl()
    {
        cout << "ImageTextSpider:Crawl" << endl;
    }
};

class VideoSpider : public Spider
{
public:
    virtual void Crawl()
    {
        cout << "VideoSpider::Crawl" << endl;
    }
};

class SpiderFactory
{
public:
    static shared_ptr<Spider> CreateSpyder(SPIDERTYPE type)
    {
        switch (type)
        {
        case SPIDERTYPE::TEXT:
            return make_shared<TextSpider>();
        case SPIDERTYPE::IMAGE:
            return make_shared<ImageSpider>();
        case SPIDERTYPE::VIDEO:
            return make_shared<VideoSpider>();
        default:
            return nullptr;
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TextSpider s;
    s.Crawl();

    // Simple Factory Model
    SpiderFactory::CreateSpyder(SPIDERTYPE::IMAGE)->Crawl();
    SpiderFactory::CreateSpyder(SPIDERTYPE::VIDEO)->Crawl();
    // Factory Method
    // TextImageFactory and TextImageSpider
    shared_ptr<MySpiderFactory> textImageFactory = make_shared<MyTextImageSpiderFactory>();
    shared_ptr<MySpider> myTextImgeSpider = textImageFactory->CreateMySpider();
    myTextImgeSpider->Crawl();

    shared_ptr<Prototype> prototype = make_shared<MyPrototype>(1, "P1");
    shared_ptr<Prototype> clone = prototype->Clone();
    cout << "Original Prototype: ";
    prototype->PrintTypeInfo();

    cout << "Cloned Prototype: ";
    clone->PrintTypeInfo();
    return a.exec();
}
