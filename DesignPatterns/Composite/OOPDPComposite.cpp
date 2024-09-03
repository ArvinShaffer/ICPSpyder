#include <QCoreApplication>
#include <iostream>
#include "MyDirectory.h"
#include "MyFile.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Transparent combination mode
    // Root:
        // A: b.txt, c.txt
        // B: d.txt
    // auto fileB = std::make_shared<MyFile>("b.txt");
    // auto fileC = std::make_shared<MyFile>("c.txt");
    // auto fileD = std::make_shared<MyFile>("d.txt");

    // auto directoryA = std::make_shared<MyDirectory>("Folder A");
    // directoryA->Add(fileB);
    // directoryA->Add(fileC);

    // auto directoryB = std::make_shared<MyDirectory>("Folder B");
    // directoryB->Add(fileD);

    // auto directoryRoot = std::make_shared<MyDirectory>("Root");
    // directoryRoot->Add(directoryA);
    // directoryRoot->Add(directoryB);

    // directoryRoot->Display();

    // safe combination mode
        // Root:
        // A: c.txt
        // B: d.txt
    auto fileB = std::make_shared<MyFile2>("b.txt");
    auto fileC = std::make_shared<MyFile2>("c.txt");
    auto fileD = std::make_shared<MyFile2>("d.txt");

    auto directoryA = std::make_shared<MyDirectory2>("Folder A");
    directoryA->Add(fileB);
    directoryA->Add(fileC);

    auto directoryB = std::make_shared<MyDirectory2>("Folder B");
    directoryB->Add(fileD);

    auto directoryRoot = std::make_shared<MyDirectory2>("Root");
    directoryRoot->Add(directoryA);
    directoryRoot->Add(directoryB);

    directoryA->Remove(fileB);

    directoryRoot->Display();
    return a.exec();
}
