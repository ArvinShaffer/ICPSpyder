#include <QCoreApplication>
#include <iostream>
#include "CheckedStream.h"
#include "GZipStream.h"
#include "Serializedstream.h"

//class MyStream
//{
//
//};
//class SerilaizedStream1 :public MyStream
//{
//
//};
//class CheckedStream1 :public SerilaizedStream1
//{
//
//};
//class GZipStream1 :public CheckedStream1
//{
//
//};
//
//class SerilaizedStream2 :public MyStream
//{
//
//};
//class  GZipStream2:public SerilaizedStream2
//{
//
//};
//
//class CheckedStream3 :public MyStream
//{
//
//};
//class GZipStream3:public CheckedStream3
//{
//
//};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::shared_ptr<MyStream> myStream = std::make_shared<MyConcreateStream>();
    // check, Serialized, gzip,
    //std::shared_ptr<MyStream> myCheckStream = std::make_shared<CheckedStream>(myStream);
    //std::shared_ptr<MyStream> myCheckAndGzipStream = std::make_shared<GZipStream>(myCheckStream);
    //myCheckAndGzipStream->OP();

    // check, serialized, gzip
    std::shared_ptr<MyStream> mySerializedStream = std::make_shared<Serializedstream>(myStream);
    std::shared_ptr<MyStream> mySerializedAndGzipStream = std::make_shared<GZipStream>(mySerializedStream);
    std::shared_ptr<MyStream> myStream3 = std::make_shared<CheckedStream>(mySerializedAndGzipStream);
    myStream3->OP();
    return a.exec();
}
