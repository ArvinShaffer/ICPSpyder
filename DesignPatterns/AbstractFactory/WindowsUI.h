#ifndef WINDOWSUI_H
#define WINDOWSUI_H
#include "UI.h"
#include <iostream>
using namespace std;

class WindowsButton: public PushButton
{
public:
    virtual void Click()
    {
        cout << "WindowsButton::Click" << endl;
    }
    virtual void Close()
    {
        cout << "WindowsButton::Close" << endl;
    }
};

class WindowsWindow: public MainWindow
{
public:
    virtual void Show()
    {
        cout << "WindowsWindow::Show" << endl;
    }
    virtual void Close()
    {
        cout << "WindowsWindow::Close" << endl;
    }
};

class WindowsFactory: public GUIFactory
{
public:
    virtual shared_ptr<PushButton> CreateButton()
    {
        return make_shared<WindowsButton>();
    }
    virtual shared_ptr<MainWindow> CreateWindow()
    {
        return make_shared<WindowsWindow>();
    }
};

#endif // WINDOWSUI_H
