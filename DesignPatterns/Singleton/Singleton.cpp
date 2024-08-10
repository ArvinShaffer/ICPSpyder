#include "Singleton.h"

// C++ 98
Singleton98* Singleton98::m_instance = nullptr;
std::mutex Singleton98::m_mutex;

// C++ 11
std::unique_ptr<Singleton11> Singleton11::m_instance;
std::once_flag Singleton11::m_flag;

SingletonH SingletonH::instance;
