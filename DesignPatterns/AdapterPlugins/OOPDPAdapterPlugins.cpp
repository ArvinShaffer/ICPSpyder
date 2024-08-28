#include <QCoreApplication>
#include <iostream>
#include "ScreenShotPlugin.h"
#include "SpiderPlugin.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    PluginsManager pluginsManager;

    // create plugins
    shared_ptr<ScreenShotPlugin> ssP = make_shared<ScreenShotPlugin>();
    shared_ptr<SpiderPlugin> sP = make_shared<SpiderPlugin>();
    pluginsManager.AddPlugin(ssP);
    pluginsManager.AddPlugin(sP);

    return a.exec();
}
