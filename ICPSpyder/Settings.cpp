#include "Settings.h"

void Settings::SetValue(const QString &key, const QVariant &value) {
    m_settingMap[key] = value;
}


QVariant Settings::Getvalue(const QString &key, const QVariant &defaultValue) const {
    return m_settings.value(key, defaultValue);
}
