#include "ICPlogger.h"

void ICPlogger::LogInfo(const QString& message)
{
    Log("INFO", message);
}

void ICPlogger::LogWarning(const QString& message)
{
    Log("Warning", message);
}

void ICPlogger::LogError(const QString& message)
{
    Log("Error", message);
}

void ICPlogger::LogCriticalError(const QString& message)
{
    Log("CriticalError", message);
}

