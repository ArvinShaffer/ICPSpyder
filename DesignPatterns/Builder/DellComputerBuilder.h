#ifndef DELLCOMPUTERBUILDER_H
#define DELLCOMPUTERBUILDER_H
#include "ComputerBuilder.h"

class DellComputerBuilder : public ComputerBuilder
{
public:
    DellComputerBuilder()
    {
        m_computer = make_shared<Computer>();
    }
    virtual void BuildCPU()
    {
        m_computer->SetCPU("Intel i5-13500HX");
    }
    virtual void BuildMemory()
    {
        m_computer->SetMemory("16G LPDDR 4800MHz");
    }
    virtual void BuildStorage()
    {
        m_computer->SetStorage("512G PCLE 4.0 SSD");
    }
    virtual Computer CreateComputer()
    {
        return *m_computer;
    }
private:
    shared_ptr<Computer> m_computer;
};

#endif // DELLCOMPUTERBUILDER_H
