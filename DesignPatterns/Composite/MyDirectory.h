#ifndef MYDIRECTORY_H
#define MYDIRECTORY_H
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "FileSystemComponent.h"
using namespace std;

class MyDirectory : public FileSystemComponent
{
private:
    std::string m_name;
    std::vector<std::shared_ptr<FileSystemComponent>> m_children;
public:
    MyDirectory(const std::string& name):m_name(name){}
    virtual void Display()
    {
        // show himself
        std::cout << "Directory Name: " << m_name << std::endl;
        // show internal substructure
        for (auto & child : m_children)
        {
            child->Display();
        }
    }
    virtual void Add(std::shared_ptr<FileSystemComponent> component)
    {
        m_children.push_back(component);
    }
    virtual void Remove(std::shared_ptr<FileSystemComponent> component)
    {
        auto it = std::find(m_children.begin(), m_children.end(), component);
        if (it != m_children.end())
        {
            m_children.erase(it);
        }
    }
};

class MyDirectory2 : public FileSystemComponent2
{
private:
    std::string m_name;
    std::vector<std::shared_ptr<FileSystemComponent2>> m_children;
public:
    MyDirectory2(const std::string& name) : m_name(name) {}
    virtual void Display()
    {
        // show himself
        std::cout << "Directory Name: " << m_name << std::endl;
        // show internal substructure
        for (auto& child : m_children)
        {
            child->Display();
        }
    }
    virtual void Add(std::shared_ptr<FileSystemComponent2> component)
    {
        m_children.push_back(component);
    }

    virtual void Remove(std::shared_ptr<FileSystemComponent2> component)
    {
        auto it = std::find(m_children.begin(), m_children.end(), component);
        if (it != m_children.end())
        {
            m_children.erase(it);
        }
    }

};





#endif // MYDIRECTORY_H
