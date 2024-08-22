#ifndef LENEVOCOMPUTERBUILDER_H
#define LENEVOCOMPUTERBUILDER_H
#include "ComputerBuilder.h"

class LenevoComputerBuilder : public ComputerBuilder
{
public:
    LenevoComputerBuilder()
    {
        m_computer = make_shared<Computer>();
    }
    virtual void BuildCPU()
    {
        m_computer->SetCPU("AMD7 7840H");
    }
    virtual void BuildMemory()
    {
        m_computer->SetMemory("16G LPDDR55600MHz");
    }
    virtual void BuildStorage()
    {
        m_computer->SetStorage("1TB PCLE 4.0 SSD");
    }
    virtual Computer CreateComputer()
    {
        return *m_computer;
    }
private:
    shared_ptr<Computer> m_computer;
};

#endif // LENEVOCOMPUTERBUILDER_H
