#ifndef SPIDERPLUGIN_H
#define SPIDERPLUGIN_H
#include "Plugin.h"

class SpiderPlugin : public Plugin
{
public:
    virtual bool Execute()
    {
        cout << "SpiderPlugin::Execute" << endl;
        return true;
    }
    virtual ~SpiderPlugin()
    {
        cout << "SpiderPlugin::~SpiderPlugin" << endl;
    }
};

#endif // SPIDERPLUGIN_H
