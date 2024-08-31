#ifndef GZIPSTREAM_H
#define GZIPSTREAM_H
#include "Decorator.h"

class GZipStream : public StreamDecorator
{
public:
    GZipStream(std::shared_ptr<MyStream> myStream) : StreamDecorator(myStream) {}
    virtual void OP()
    {
        // TODO Serialized
        cout << "GZip Stream...." << endl;
        StreamDecorator::OP();
    }
};

#endif // GZIPSTREAM_H
