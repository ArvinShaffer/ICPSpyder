#include <QCoreApplication>
#include <iostream>
#include "WindowsUI.h"
#include "MacOSUI.h"
#include "UbuntuUI.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    shared_ptr<GUIFactory> factory;

#ifdef _WIN32
    factory = make_shared<WindowsFactory>();
#elif __APPLE__
    factory = make_shared<MacOSFactory>();
#elif __linux__
    factory = make_shared<UbuntuFactory>();
#else
    factory = make_shared<DefaultFactory>();
#endif

    // No interference with client logic
    shared_ptr<PushButton> button = factory->CreateButton();
    shared_ptr<MainWindow> window = factory->CreateWindow();

    button->Click();
    button->Close();

    window->Show();
    window->Close();
    return a.exec();
}
