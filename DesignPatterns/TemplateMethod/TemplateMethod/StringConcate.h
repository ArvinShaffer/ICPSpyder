#ifndef STRINGCONCATE_H
#define STRINGCONCATE_H
#include <string>
#include "TestCase.h"
using namespace std;

class StringConcate
{
public:
    StringConcate() {m_a = m_b = "";}

    void SetA(const string& a)
    {
        m_a = a;
    }

    void SetB(const string& b)
    {
        m_b = b;
    }

    string Add()
    {
        return m_a + m_b;
    }

private:
    string m_a;
    string m_b;
};

class TestStringAddition : public TestCase<string>
{
public:
    TestStringAddition(const string& a, const string& b, const string& result) : m_a(a), m_b(b), expectedResult(result) {}
protected:
    virtual void SetEnv()
    {
        m_strAddition.SetA(m_a);
        m_strAddition.SetB(m_b);
        m_expectedResult = expectedResult;
    }

    virtual string Run()
    {
        return m_strAddition.Add();
    }
private:
    StringConcate m_strAddition;
    string m_a;
    string m_b;
    string expectedResult;
};
#endif // STRINGCONCATE_H
