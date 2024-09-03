#ifndef FILESYSTEMCOMPONENT_H
#define FILESYSTEMCOMPONENT_H
#include <memory>
#include <iostream>
using namespace std;

// Transparent combination mode
class FileSystemComponent
{
public:
    virtual void Display() = 0;

    virtual void Add(std::shared_ptr<FileSystemComponent> component) = 0;
    virtual void Remove(std::shared_ptr<FileSystemComponent> component) = 0;
};

// Safe combination mode
class FileSystemComponent2
{
public:
    virtual void Display() = 0;
};

#endif // FILESYSTEMCOMPONENT_H
