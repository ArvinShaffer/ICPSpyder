#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

class Observer
{
public:
    virtual void Update(const string& message) = 0;
};

class Subject
{
public:
    virtual void NotifyObservers() = 0;
    virtual void RegisterObservers(shared_ptr<Observer> observer) = 0;
    virtual void RemoveObservers(shared_ptr<Observer> observer) = 0;
};

class News: public Subject
{
private:
    vector<shared_ptr<Observer>> m_observers;
    string m_state;
public:
    virtual void NotifyObservers()
    {
        for (const auto& observer : m_observers)
        {
            observer->Update(m_state);
        }
    }
    virtual void RegisterObservers(shared_ptr<Observer> observer)
    {
        m_observers.push_back(observer);
    }
    virtual void RemoveObservers(shared_ptr<Observer> observer)
    {
        auto it = find(m_observers.begin(), m_observers.end(), observer);
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

#endif // SUBJECT_H
