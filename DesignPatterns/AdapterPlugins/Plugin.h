#ifndef PLUGIN_H
#define PLUGIN_H
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

class Plugin
{
public:
    virtual bool Execute() = 0;
    virtual ~Plugin() {}
};

class PluginsManager
{
public:
    void AddPlugin(shared_ptr<Plugin> plugin)
    {
        m_plugins.push_back(plugin);
    }
    void ExecutesAllPlugins()
    {
        for (const auto& p : m_plugins)
        {
            p->Execute();
        }
    }
    void UnLoadPlugins()
    {
        m_plugins.clear();
    }
private:
    vector<shared_ptr<Plugin>> m_plugins;
};

#endif // PLUGIN_H
