#ifndef ICPLOGGER_H
#define ICPLOGGER_H
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QDebug>
#include "Singleton.h"

class ICPlogger : public Singleton<ICPlogger>
{
    friend class Singleton<ICPlogger>;
public:
    void LogInfo(const QString& message);
    void LogWarning(const QString& message);
    void LogError(const QString& message);
    void LogCriticalError(const QString& message);

private:
    ICPlogger() {
        m_file.setFileName("ICPlogger.txt");
        if (! m_file.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text))
        {
            qWarning() << "Cannot open ICPlogger File" ;
        }
    }

    void Log(const QString& level, const QString& message) {
        if (m_file.isOpen() && m_file.isWritable()) {
            QTextStream logStream(&m_file);
            logStream << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " ";
            logStream << level << ": " << message << Qt::endl;
        }
        else {
            qWarning() << "Cannot write to ICPlogger File";
        }
        QTextStream(stdout) << level << ": " << message << Qt::endl;
    }

    QFile m_file;
};

#endif // ICPLOGGER_H
