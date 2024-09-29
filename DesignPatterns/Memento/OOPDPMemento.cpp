#include <iostream>
using namespace std;

#include "UserDataBaseMemento.h"

int main(int argc, char *argv[])
{
    UserDataBase database;
    database.InsertUser(User(1, "Alice"));
    cout << "Current State: " << endl;
    database.DisplayUsers();
    UserDataBaseMemento mem = database.CreateMemento();

    database.InsertUser(User(2, "Bob"));
    database.InsertUser(User(3, "Cherry"));
    cout << "Current States: " << endl;
    database.DisplayUsers();

    // back to second data
    cout << "Rolling back to state 1: " << endl;
    database.RestoreMemento();
    database.DisplayUsers();

    return 0;
}
