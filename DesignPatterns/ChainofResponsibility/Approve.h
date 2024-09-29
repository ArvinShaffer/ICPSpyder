#ifndef APPROVE_H
#define APPROVE_H
#include <string>
#include <iostream>
using namespace std;

enum class ApproType
{
    Budget,
    ShortVacation,
    LongVacation,
    Resign
};

struct Approve
{
    Approve(const string& name, ApproType type):m_name(name), m_type(type)
    {
    }
    string m_name;
    ApproType m_type;
};

class Approver
{
public:
    Approver(const string& name):m_name(name), m_nextApprover(nullptr)
    {

    }
    void SetNextApprover(Approver* next)
    {
        m_nextApprover = next;
    }
    virtual bool ProcessRequest(Approve approve) = 0;
protected:
    string m_name;
    Approver* m_nextApprover;
};

class DepartmentManager:public Approver
{
public:
    DepartmentManager(const string& name):Approver(name){}
    virtual bool ProcessRequest(Approve approve)
    {
        if (approve.m_type == ApproType::Budget)
        {
            cout << m_name << " approved " << approve.m_name << " the expense report " << endl;
            return true;
        }
        else if (approve.m_type == ApproType::ShortVacation)
        {
            cout << m_name << " approved " << approve.m_name << " the short vaction report " << endl;
        }
        else if (approve.m_type == ApproType::Resign)
        {
            cout << m_name << " approved " << approve.m_name << " the resign report " << endl;
        }
        else if (approve.m_type == ApproType::LongVacation)
        {
            cout << m_name << " approved " << approve.m_name << " the long vaction report " << endl;
        }
        else
        {
            ;
        }

        if (m_nextApprover != nullptr)
        {
            return m_nextApprover->ProcessRequest(approve);
        }
        return false;
    }
};

class HRManager :public Approver
{
public:
    HRManager(const string& name) :Approver(name) {}
    virtual bool ProcessRequest(Approve approve)
    {
        if (approve.m_type == ApproType::Resign)
        {
            cout << m_name << " approved " << approve.m_name << " the resign report " << endl;
            return true;
        }
        else if(approve.m_type == ApproType::LongVacation)
        {
            cout << m_name << " approved " << approve.m_name << " the long vacation report " << endl;
        }
        else
        {
            ;
        }

        if (m_nextApprover != nullptr)
        {
            return m_nextApprover->ProcessRequest(approve);
        }
        return false;
    }
};

class President:public Approver
{
public:
    President(const string& name):Approver(name){}
    virtual bool ProcessRequest(Approve approve)
    {
        if (approve.m_type == ApproType::LongVacation)
        {
            cout << m_name << " approved " << approve.m_name << " the long vacation report " << endl;
            return true;
        }
        else
        {
            ;
        }
        if (m_nextApprover != nullptr)
        {
            return m_nextApprover->ProcessRequest(approve);
        }
        return false;
    }
};


#endif // APPROVE_H
