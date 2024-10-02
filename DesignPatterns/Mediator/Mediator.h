#ifndef MEDIATOR_H
#define MEDIATOR_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Mediator;

class Colleague
{
public:
    Colleague(Mediator* mediator, const string& name) : m_mediator(mediator), m_name(name){}
    virtual void Send(const string& message) = 0;
    virtual void Receive(const string& senderName, const string& message) = 0;
    const string& GetName() const
    {
        return m_name;
    }
protected:
    Mediator* m_mediator;
    string m_name;
};

class Mediator
{
public:
    virtual void SendMessage(const Colleague* sender, const string& message) = 0;
    virtual void AddColleague(Colleague* colleague) = 0;
};

class ConcreMeiator:public Mediator
{
public:
    virtual void SendMessage(const Colleague* sender, const string& message)
    {
        for (auto c : m_colleagues)
        {
            if (c != sender)
            {
                c->Receive(sender->GetName(), message);
            }
        }
    }
    virtual void AddColleague(Colleague* colleague)
    {
        m_colleagues.push_back(colleague);
    }
private:
    vector<Colleague*> m_colleagues;
};

class ConcreColleague:public Colleague
{
public:
    ConcreColleague(Mediator* mediator, const string& name):Colleague(mediator, name)
    {
        mediator->AddColleague(this);
    }
    virtual void Send(const string& message)
    {
        m_mediator->SendMessage(this, message);
    }
    virtual void Receive(const string& senderName, const string& message)
    {
        cout << m_name << " received: " << message << " from " << senderName << endl;
    }
};


#endif // MEDIATOR_H
