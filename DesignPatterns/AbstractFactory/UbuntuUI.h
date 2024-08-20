#ifndef UBUNTUUI_H
#define UBUNTUUI_H
#include "UI.h"
#include <iostream>
using namespace std;

class UbuntuButton: public PushButton
{
public:
    virtual void Click()
    {
        cout << "UbuntuButton::Click" << endl;
    }
    virtual void Close()
    {
        cout << "UbuntuButton::Close" << endl;
    }
};

class UbuntuWindow: public MainWindow
{
public:
    virtual void Show()
    {
        cout << "UbuntuWindow::Show" << endl;
    }
    virtual void Close()
    {
        cout << "UbuntuWindow::Close" << endl;
    }
};

class UbuntuFactory: public GUIFactory
{
public:
    virtual shared_ptr<PushButton> CreateButton()
    {
        return make_shared<UbuntuButton>();
    }
    virtual shared_ptr<MainWindow> CreateWindow()
    {
        return make_shared<UbuntuWindow>();
    }
};

#endif // UBUNTUUI_H


