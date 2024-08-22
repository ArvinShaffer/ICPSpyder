#ifndef MYCOMPUTER_H
#define MYCOMPUTER_H
#include <string>
#include <iostream>
#include <memory>
using namespace std;

class MyComputer
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
class MyComputerBuilder
{
public:
    MyComputerBuilder()
    {
        m_computer = make_shared<MyComputer>();
    }
    MyComputerBuilder& BuildCPU(const string& cpu)
    {
        m_computer->SetCPU(cpu);
        return *this;
    }
    MyComputerBuilder& BuilderMemory(const string& memory)
    {
        m_computer->SetMemory(memory);
        return *this;
    }
    MyComputerBuilder& BuildStorage(const string& storage)
    {
        m_computer->SetStorage(storage);
        return *this;
    }
    MyComputer CreateComputer()
    {
        return *m_computer;
    }
private:
    shared_ptr<MyComputer> m_computer;
};

#endif // MYCOMPUTER_H
