#ifndef CHECKEDSTREAM_H
#define CHECKEDSTREAM_H
#include "Decorator.h"
class CheckedStream : public StreamDecorator
{
public:
    CheckedStream(std::shared_ptr<MyStream> myStream) : StreamDecorator(myStream) {}
    virtual void OP()
    {
        // TODO Serialized
        cout << "Check Stream..." << endl;
        StreamDecorator::OP();
    }
};

#endif // CHECKEDSTREAM_H
