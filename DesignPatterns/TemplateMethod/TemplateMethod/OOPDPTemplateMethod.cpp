#include <QCoreApplication>
#include <iostream>
#include "Addition.h"
#include "StringConcate.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestAddition testAddition(1, 2, 3);
    testAddition.RunTest();

    TestStringAddition testStringAddition("hello", "world", "helloworld");
    testStringAddition.RunTest();

    return a.exec();
}
