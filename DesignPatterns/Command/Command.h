#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <stack>
#include <memory>
using namespace std;

class Command
{
public:
    virtual void Executable(string& text) = 0;
    virtual void Undo(string& text) = 0;
    virtual void Redo(string& text) = 0;
};

class TextCommand : public Command
{
public:
    TextCommand(const string& text) : m_NewText(text), m_prevText("") {}

    virtual void Executable(string& text)
    {
        m_prevText = text;
        text = m_NewText;
    }
    virtual void Undo(string& text)
    {
        text = m_prevText;
    }
    virtual void Redo(string& text)
    {
        Executable(text);
    }
private:
    string m_prevText;
    string m_NewText;
};

class DocumentEditor
{
public:
    DocumentEditor() : m_text("") {}

    void ExecuteCommand(shared_ptr<Command> cmd)
    {
        cmd->Executable(m_text);
        m_undoStack.push(cmd);
    }

    void Undo()
    {
        if (!m_undoStack.empty())
        {
            shared_ptr<Command> cmd = m_undoStack.top();
            cmd->Undo(m_text);
            m_undoStack.pop();
            m_RedoStack.push(cmd);
        }
    }

    void Redo()
    {
        if (!m_RedoStack.empty())
        {
            shared_ptr<Command> cmd = m_RedoStack.top();
            cmd->Redo(m_text);
            m_RedoStack.pop();
            m_undoStack.push(cmd);
        }
    }

    string GetText() const
    {
        return m_text;
    }
private:
    string m_text;
    stack<shared_ptr<Command>> m_undoStack;
    stack<shared_ptr<Command>> m_RedoStack;
};


#endif // COMMAND_H
