#ifndef ADDITION_H
#define ADDITION_H
#include "TestCase.h"

class Addition
{
public:
    Addition() { m_a = m_b = 0; }
    void SetA(int a)
    {
        m_a = a;
    }

    void SetB(int b)
    {
        m_b = b;
    }

    int Add()
    {
        return m_a + m_b;
    }

private:
    int m_a;
    int m_b;
};

class TestAddition:public TestCase<int>
{
public:
    TestAddition(int a, int b, int result) : m_a(a), m_b(b), expectedResult(result) {}
protected:
    virtual void SetEnv()
    {
        m_addition.SetA(m_a);
        m_addition.SetB(m_b);
        m_expectedResult = expectedResult;
    }
    virtual int Run()
    {
        return m_addition.Add();
    }
private:
    Addition m_addition;
    int m_a;
    int m_b;
    int expectedResult;
};
#endif // ADDITION_H
