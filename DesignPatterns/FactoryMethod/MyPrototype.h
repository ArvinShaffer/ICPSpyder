#ifndef MYPROTOTYPE_H
#define MYPROTOTYPE_H
#include <string>
#include <iostream>
#include "Prototype.h"
using namespace std;

class MyPrototype : public Prototype
{
public:
    MyPrototype(int id, const string& name):m_id(id), m_name(name)
    {}
    virtual shared_ptr<Prototype> Clone() const
    {
        return make_shared<MyPrototype>(m_id, m_name);
    }
    virtual void PrintTypeInfo() const
    {
        cout << "ID: " << m_id << ", Name: " << m_name << endl;
    }
private:
    int m_id;
    string m_name;
};

#endif // MYPROTOTYPE_H
