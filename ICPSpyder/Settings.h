#ifndef SETTINGS_H
#define SETTINGS_H
#include <QSettings>
#include <QDebug>
#include <QMap>
#include <QObject>
#include "Singleton.h"

class Settings : public Singleton<Settings>, public QObject
{
    friend class Singleton<Settings>;

public slots:
    void SyncSettings() {
        for (auto it = m_settingMap.constBegin(); it != m_settingMap.cend(); ++it)
        {
            m_settings.setValue(it.key(), it.value());
        }
        m_settings.sync();
    }
public:
    void SetValue(const QString &key, const QVariant &value);
    QVariant Getvalue(const QString &key, const QVariant &defaultValue = QVariant()) const;

private:
    Settings() {}
    QSettings m_settings {"ICPSpyderSettings.ini", QSettings::IniFormat};
    QMap<QString, QVariant> m_settingMap;
};

#endif // SETTINGS_H
