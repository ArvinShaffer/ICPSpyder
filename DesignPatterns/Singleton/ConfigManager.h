#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H
#include <mutex>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <memory>
using namespace std;

static const string configFileName = "config.ini";

class ConfigManager
{
public:
    static ConfigManager& getInstance()
    {
        call_once(m_flag, []() {
            m_instance.reset(new ConfigManager);
        });
        return *m_instance;
    }
    string GetConfigValue(const string& key)
    {
        if (m_configData.find(key) != m_configData.end())
        {
            return m_configData[key];
        }
        else
        {
            return "";
        }
    }
    void SetConfigValue(const string& key, const string& value)
    {
        m_configData[key] = value;
        SaveConfigFile(configFileName);
    }
private:
    void LoadConfigFile(const string& fileName)
    {
        ifstream configFile(fileName);
        if (!configFile.is_open()){
            cerr << "Failed to open config file: " << fileName << endl;
            return;
        }
        string line;
        while (getline(configFile, line)) {
            istringstream iss(line);
            string key, value;

            size_t found_open_bracket = line.find('[');
            size_t found_close_bracket = line.find(']');

            if (found_open_bracket != string::npos && found_close_bracket != string::npos) {
                continue;
            }
            else if (found_open_bracket != string::npos) {
                cerr << "Only '[' found in the line." << endl;
            }
            else if (found_close_bracket != string::npos) {
                cerr << "Only ']' found in the line." << endl;
            }
            else {
                ;
            }
            if (getline(iss, key, '=') && getline(iss, value)) {
                key.erase(0, key.find_first_not_of(" \t"));
                key.erase(key.find_last_not_of(" \t") + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);
                if (!key.empty()) {
                    m_configData[key] = value;
                }
            }
        }
        configFile.close();
    }

    void SaveConfigFile(const string& fileName)
    {
        ofstream configFile(fileName);
        if (!configFile.is_open()) {
            cerr << "Failed to open config file for writing: " << fileName << endl;
            return ;
        }
        configFile << "[Server]" << endl;
        for (const auto& pair : m_configData) {
            configFile << pair.first << " = " << pair.second << endl;
        }
        configFile.close();
    }
    ConfigManager()
    {
        LoadConfigFile(configFileName);
    }
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager(ConfigManager&&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;
    ConfigManager& operator=(ConfigManager&&) = delete;
    static unique_ptr<ConfigManager> m_instance;
    static once_flag m_flag;
    map<string, string> m_configData;
};

#endif // CONFIGMANAGER_H
