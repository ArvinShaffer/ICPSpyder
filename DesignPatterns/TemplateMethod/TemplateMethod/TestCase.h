#ifndef TESTCASE_H
#define TESTCASE_H
#include <assert.h>

template<typename T>
class TestCase
{
public:
    // Input variables, run interface functions, check test results, and clean up aftermath
    void RunTest()
    {
        SetEnv();
        T result = Run();
        Check(result);
    }
protected:
    virtual void SetEnv() {};
    virtual T Run() = 0;
    virtual void Check(T result) { assert(m_expectedResult == result);}
protected:
    T m_expectedResult;
};

#endif // TESTCASE_H
