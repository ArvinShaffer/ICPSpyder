#ifndef USERDATABASEMEMENTO_H
#define USERDATABASEMEMENTO_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
public:
    User(int id, const string& name):m_id(id), m_name(name) {}

    int GetId() const
    {
        return m_id;
    }

    const string& GetName() const
    {
        return m_name;
    }
private:
    int m_id;
    string m_name;
};

class UserDataBaseMemento
{
public:
    UserDataBaseMemento(const vector<User>& states) : m_states(states){}
    vector<User>& GetState()
    {
        ifstream file("memento.txt");
        m_states.clear();
        string line;
        while (getline(file, line))
        {
            unsigned int commPas = line.find(',');
            if (commPas != string::npos)
            {
                int id = std::stoi(line.substr(0, commPas));
                string name = line.substr(commPas + 1);
                m_states.push_back(User(id, name));
            }
        }
        file.close();
        return m_states;
    }
private:
    vector<User> m_states;
};

class UserDataBase
{
public:
    bool InsertUser(const User& user)
    {
        m_states.push_back(user);
        return true;
    }

    void DisplayUsers() const
    {
        for (const User& user : m_states)
        {
            cout << "User ID: " << user.GetId() << " , Name: " << user.GetName() << endl;
        }
    }

    UserDataBaseMemento CreateMemento()
    {
        UserDataBaseMemento mem = UserDataBaseMemento(m_states);
        // TODO: Serialize and save data to disk
        ofstream file("memento.txt");
        for (const User& user : m_states)
        {
            file << user.GetId() << " , " << user.GetName() << endl;
        }
        file.close();
        return mem;
    }

    // bool RestoreMemento(UserDataBaseMemento& mem)
    // {
    //     m_states = mem.GetState();
    //     return true;
    // }

    UserDataBaseMemento RestoreMemento()
    {
        ifstream file("memento.txt");
        m_states.clear();
        string line;
        while (getline(file, line))
        {
            unsigned int commPas = line.find(',');
            if (commPas != string::npos)
            {
                int id = std::stoi(line.substr(0, commPas));
                string name = line.substr(commPas + 1);
                m_states.push_back(User(id, name));
            }
        }
        file.close();
        return UserDataBaseMemento(m_states);
    }
private:
    vector<User> m_states;
};


#endif // USERDATABASEMEMENTO_H
