#ifndef UI_H
#define UI_H
#include <memory>
using namespace std;

class PushButton
{
public:
    virtual void Click() = 0;
    virtual void Close() = 0;
};

class MainWindow
{
public:
    virtual void Show() = 0;
    virtual void Close() = 0;
};

class GUIFactory
{
public:
    virtual shared_ptr<PushButton> CreateButton() = 0;
    virtual shared_ptr<MainWindow> CreateWindow() = 0;
};

#endif // UI_H
