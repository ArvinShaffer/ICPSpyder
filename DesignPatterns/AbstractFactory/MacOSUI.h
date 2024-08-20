#ifndef MACOSUI_H
#define MACOSUI_H
#include "UI.h"
#include <iostream>
using namespace std;

class MacOSButton: public PushButton
{
public:
    virtual void Click()
    {
        cout << "MacOSButton::Click" << endl;
    }
    virtual void Close()
    {
        cout << "MacOSButton::Close" << endl;
    }
};

class MacOSWindow: public MainWindow
{
public:
    virtual void Show()
    {
        cout << "MacOSWindow::Show" << endl;
    }
    virtual void Close()
    {
        cout << "MacOSWindow::Close" << endl;
    }
};

class MacOSFactory: public GUIFactory
{
public:
    virtual shared_ptr<PushButton> CreateButton()
    {
        return make_shared<MacOSButton>();
    }
    virtual shared_ptr<MainWindow> CreateWindow()
    {
        return make_shared<MacOSWindow>();
    }
};

#endif // MACOSUI_H
