#ifndef SCREENSHOTPLUGIN_H
#define SCREENSHOTPLUGIN_H
#include "Plugin.h"

class ScreenShotPlugin : public Plugin
{
public:
    virtual bool Execute()
    {
        cout << "ScreenShotPlugin::Execute" << endl;
        return true;
    }
    virtual ~ScreenShotPlugin()
    {
        cout << "ScreenShotPlugin::~ScreenShotPlugin" << endl;
    }
};

#endif // SCREENSHOTPLUGIN_H
