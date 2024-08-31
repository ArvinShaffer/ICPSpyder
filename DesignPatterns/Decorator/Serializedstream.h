#ifndef SERIALIZEDSTREAM_H
#define SERIALIZEDSTREAM_H
#include "Decorator.h"

class Serializedstream : public StreamDecorator
{
public:
    Serializedstream(std::shared_ptr<MyStream> myStream) : StreamDecorator(myStream){}
    virtual void OP()
    {
        // TODO Serialized
        cout << "Serialize Stream..." << endl;
        StreamDecorator::OP();
    }
};

#endif // SERIALIZEDSTREAM_H
