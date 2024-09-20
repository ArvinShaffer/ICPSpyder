#include <QCoreApplication>
#include <iostream>
#include "Command.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DocumentEditor editor;

    editor.ExecuteCommand(make_shared<TextCommand>("hello"));
    editor.ExecuteCommand(make_shared<TextCommand>("world"));
    editor.ExecuteCommand(make_shared<TextCommand>("command"));
    cout << editor.GetText() << endl;

    editor.Undo();
    editor.Undo();
    cout << editor.GetText() << endl;
    editor.Redo();
    cout << editor.GetText() << endl;
    editor.Redo();
    cout << editor.GetText() << endl;
    editor.Undo();
    cout << editor.GetText() << endl;


    return a.exec();
}
