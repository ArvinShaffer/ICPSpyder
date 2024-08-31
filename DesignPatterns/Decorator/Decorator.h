#ifndef DECORATOR_H
#define DECORATOR_H
#include <memory>
#include <iostream>
using namespace std;

class MyStream
{
public:
    virtual void OP() = 0;
};

class MyConcreateStream:public MyStream
{
public:
    virtual void OP()
    {
        cout << "MyConcreateStream::OP" << endl;
    }
};

class StreamDecorator : public MyStream
{
private:
    std::shared_ptr<MyStream> m_myStream;
public:
    StreamDecorator(std::shared_ptr<MyStream> myStream) : m_myStream(myStream) {}
    virtual void OP()
    {
        if (m_myStream)
        {
            m_myStream->OP();
        }
    }
};

#endif // DECORATOR_H
