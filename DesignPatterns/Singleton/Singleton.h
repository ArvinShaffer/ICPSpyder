#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>
#include <mutex>
#include <iostream>
using namespace std;

// C++ 98
class Singleton98
{
public:
    static Singleton98* getInstance()
    {
        // double check
        if (m_instance == nullptr)
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (m_instance == nullptr)
            {
                m_instance = new Singleton98();
            }
        }
        return m_instance;
    }
    void Test()
    {
        cout << "Singleton98: " << this << endl;
        nullptr;
    }
private:
    Singleton98() = default;
    ~Singleton98() = default;
    Singleton98(const Singleton98&) = delete;
    Singleton98(Singleton98&&) = delete;
    Singleton98& operator=(const Singleton98&) = delete;
    Singleton98& operator=(Singleton98&&) = delete;

    static Singleton98* m_instance;
    static std::mutex m_mutex;
};

class Singleton11
{
public:
    static Singleton11& getInstance()
    {
        std::call_once(m_flag, []() {
            m_instance.reset(new Singleton11);
        });
        return *m_instance;
    }
    void Test()
    {
        cout << "Singleton11: " << this << endl;
        nullptr;
    }
private:
    Singleton11() = default;
    Singleton11(const Singleton11&) = delete;
    Singleton11(Singleton11&&) = delete;
    Singleton11& operator=(const Singleton11&) = delete;
    Singleton11& operator=(Singleton11&&) = delete;

    static std::unique_ptr<Singleton11> m_instance;
    static std::once_flag m_flag;
};


// C++ 11
class Singleton
{
public:
    static Singleton& GetInstance()
    {
        static Singleton instance;
        return instance;
    }
    void Test()
    {
        cout << "Singleton: " << this << endl;
        nullptr;
    }
private:
    Singleton() = default;
    ~Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};

class SingletonH
{
public:
    static SingletonH& GetInstance()
    {
        return instance;
    }
    void Test()
    {
        cout << "SingletonH: " << this << endl;
        nullptr;
    }
private:
    SingletonH() = default;
    ~SingletonH() = default;
    SingletonH(const SingletonH&) = delete;
    SingletonH(SingletonH&&) = delete;
    SingletonH& operator=(const SingletonH&) = delete;
    SingletonH& operator=(SingletonH&&) = delete;
    static SingletonH instance;
};

#endif // SINGLETON_H
