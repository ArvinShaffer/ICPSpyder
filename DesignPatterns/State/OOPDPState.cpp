#include <iostream>
#include "EditorState.h"
using namespace std;
// readonly, edit, command:wq,!q

int main(int argc, char *argv[])
{
    Editor editor;
    string input;

    while (true)
    {
        cout << "Current state is " << editor.GetState() << " , please enter: ";
        cin >> input;
        editor.HandleInput(input);
        if(editor.GetState() == "Command Mode" && (input == "::!q" || input == "::wq"))
        {
            break;
        }
    }

    return 0;
}
