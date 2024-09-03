#ifndef MYFILE_H
#define MYFILE_H
#include <string>
#include <iostream>
#include "FileSystemComponent.h"

class MyFile : public FileSystemComponent
{
private:
    std::string m_name;
public:
    MyFile(const std::string& name) : m_name(name) {}
    virtual void Display()
    {
        std::cout << "File Name: " << m_name << std::endl;
    }
    virtual void Add(std::shared_ptr<FileSystemComponent> component)
    {

    }
    virtual void Remove(std::shared_ptr<FileSystemComponent> component)
    {

    }
};

class MyFile2 : public FileSystemComponent2
{
private:
    std::string m_name;
public:
    MyFile2(const std::string& name) : m_name(name) {}
    virtual void Display()
    {
        std::cout << "File Name: " << m_name << std::endl;
    }
};

#endif // MYFILE_H
