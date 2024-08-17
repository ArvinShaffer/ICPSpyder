#include <QCoreApplication>
#include <iostream>
#include "Singleton.h"
#include "Logger.h"
#include "ConfigManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // C++ 98
    // Singleton98* s1 = Singleton98::getInstance();
    // s1->Test();
    // Singleton98* s2 = Singleton98::getInstance();
    // s2->Test();

    // // C++ 11
    // Singleton11::getInstance().Test();
    // Singleton11::getInstance().Test();

    // Singleton::GetInstance().Test();
    // Singleton::GetInstance().Test();

    // SingletonH::GetInstance().Test();
    // SingletonH::GetInstance().Test();

    // // Singleton Logger
    // Logger& logger = Logger::GetInstance();
    // logger.OpenLogFile("test.log");
    // logger.Log("Hello singleton test");
    // logger.Log("input error test", LogLevel::ERROR, __FILE__, __LINE__);

    // Singleton Config
    ConfigManager& configManager = ConfigManager::getInstance();
    string serverAddress = configManager.GetConfigValue("Address");
    string port = configManager.GetConfigValue("Port");

    cout << "Address: " << serverAddress << std::endl;
    cout << "Port: " << port << std::endl;

    configManager.SetConfigValue("Port", "8081");
    port = configManager.GetConfigValue("Port");
    cout << "Updated Port: " << port << std::endl;

    return a.exec();
}
