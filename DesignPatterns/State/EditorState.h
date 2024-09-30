#ifndef EDITORSTATE_H
#define EDITORSTATE_H
#include <string>
#include <memory>
#include <iostream>
using namespace std;

class Editor;
class CommandModeState;
class EditModeState;
class ReadOnlyModeState;

class EditorState
{
public:
    virtual void HandleInput(const string& input, Editor& editor) = 0;
    virtual ~EditorState(){}
    virtual string GetState() const = 0;
};

class CommandModeState:public EditorState
{
public:
    virtual void HandleInput(const string& input, Editor& editor);
    virtual ~CommandModeState(){}
    virtual string GetState() const
    {
        return "Command Mode";
    }
};

class EditModeState:public EditorState
{
public:
    virtual void HandleInput(const string& input, Editor& editor);
    virtual ~EditModeState(){}
    virtual string GetState() const
    {
        return "Edit Mode";
    }
};

class ReadOnlyModeState:public EditorState
{
public:
    virtual void HandleInput(const string& input, Editor& editor);
    virtual ~ReadOnlyModeState(){}
    virtual string GetState() const
    {
        return "ReadOnly Mode";
    }
};

class Editor
{
private:
    shared_ptr<EditorState> m_currentState;
public:
    Editor():m_currentState(make_shared<EditModeState>()){}

    void SetState(shared_ptr<EditorState> newState)
    {
        m_currentState = newState;
    }

    virtual string GetState() const
    {
        return m_currentState->GetState();
    }

    void HandleInput(const string& input)
    {
        m_currentState->HandleInput(input, *this);
    }
};

void CommandModeState::HandleInput(const string& input, Editor& editor)
{
    if (input == "::i")
    {
        cout << "Enter Edit Mode: " << endl;
        editor.SetState(make_shared<EditModeState>());
    }

    else if (input == "::!q")
    {
        cout << "Quit the Edit without saved" << endl;
    }

    else if (input == "::wq")
    {
        cout << "Quit the Edit with saved" << input << endl;
    }

    else
    {
        cout << "Invalid Command" << input << endl;
    }
}

void EditModeState::HandleInput(const string& input, Editor& editor)
{
    if (input == "::c")
    {
        cout << "Enter Edit Mode:" << endl;
        editor.SetState(make_shared<CommandModeState>());
    }
    else if (input == "::r")
    {
        cout << "Enter Readonly Mode:" << endl;
        editor.SetState(make_shared<ReadOnlyModeState>());
    }
    else
    {
        cout << "Inserting txt: " << input << endl;
    }
}

void ReadOnlyModeState::HandleInput(const string& input, Editor& editor)
{
    if (input == "::i")
    {
        cout << "Enter Edit Mode:" << endl;
        editor.SetState(make_shared<EditModeState>());
    }
    else
    {
        cout << "Readonly Mode not allowed edit" << endl;
    }
}


#endif // EDITORSTATE_H
