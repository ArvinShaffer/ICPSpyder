#ifndef COMPUTERBUILDER_H
#define COMPUTERBUILDER_H
#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Computer
{
public:
    void SetCPU(const string& cpu)
    {
        m_cpu = cpu;
    }
    void SetMemory(const string& memory)
    {
        m_memory = memory;
    }
    void SetStorage(const string& storage)
    {
        m_storage = storage;
    }
    void Show() const
    {
        cout << "CPU: " << m_cpu << endl;
        cout << "Memory: " << m_memory << endl;
        cout << "Storage: " << m_storage << endl;
    }

private:
    string m_cpu;
    string m_memory;
    string m_storage;
};

class ComputerBuilder
{
public:
    virtual void BuildCPU() = 0;
    virtual void BuildMemory() = 0;
    virtual void BuildStorage() = 0;
    virtual Computer CreateComputer() = 0;
};

#endif // COMPUTERBUILDER_H
