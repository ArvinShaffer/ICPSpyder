#ifndef OBSERVERS_H
#define OBSERVERS_H
#include <iostream>
#include <functional>
#include "Subject.h"
using namespace std;

class Observer1: public Observer
{
private:
    string m_id;
public:
    Observer1(const string& obID) : m_id(obID) {}
    virtual void Update(const string& message)
    {
        cout << m_id << " receving message: " << message << endl;
    }
};

class Observer2: public Observer
{
private:
    string m_id;
public:
    Observer2(const string& obID) : m_id(obID){}
    virtual void Update(const string& message)
    {
        cout << m_id << " receiving message: " << message << endl;
    }
};

class ObserverSTL
{
public:
    virtual void Update(const string& message) = 0;
};

class ObserverSTL1 : public ObserverSTL
{
private:
    string m_id;
public:
    ObserverSTL1(const string& obID) : m_id(obID){}
    virtual void Update(const string& message)
    {
        cout << m_id << " receving message: " << message << endl;
    }
};

class ObserverSTL2 : public ObserverSTL
{
private:
    string m_id;
public:
    ObserverSTL2(const string& obID) : m_id(obID){}
    virtual void Update(const string& message)
    {
        cout << m_id << " receving message: " << message << endl;
    }
};

class SubjectSTL
{
private:
    vector<function<void(const string&)>> m_observers;
    string m_state;
public:
    virtual void NotifyObservers()
    {
        for (const auto& observer:m_observers)
        {
            observer(m_state);
        }
    }

    virtual void RegisterObservers(function<void(const string&)> observer)
    {
        m_observers.push_back(observer);
    }

    virtual void RemoveObservers(function<void(const string&)> observer)
    {
        //auto it = find(m_observers.begin(), m_observers.end(), observer);
        auto it = remove_if(m_observers.begin(), m_observers.end(),
                       [observer](function<void(const string&)> other){return other.target_type() == observer.target_type();});
        if (it != m_observers.end())
        {
            m_observers.erase(it);
        }
    }

    void SetState(const string& state)
    {
        m_state = state;
        NotifyObservers();
    }
};

#endif // OBSERVERS_H







