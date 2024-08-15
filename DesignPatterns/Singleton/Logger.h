#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

enum class LogLevel
{
    FATAL_ERROR,
    ERROR,
    WARNING,
    INFO
};

static const int TIME_LEN = 100;

class Logger
{
public:
    static Logger& GetInstance()
    {
        static Logger instance;
        return instance;
    }

    void OpenLogFile(const string& fileName)
    {
        if (logFile.is_open())
        {
            logFile.close();
        }
        logFile.open(fileName, ios::out | ios::app);
    }
    void CloseLogFile()
    {
        if (logFile.is_open())
        {
            logFile.close();
        }
    }

    void Log(const string& message, LogLevel level = LogLevel::INFO, const char* fileName=nullptr, int line = -1)
    {
        string levelStr;
        switch (level)
        {
        case LogLevel::FATAL_ERROR:
            levelStr = "FATAL ERROR: ";
            break;
        case LogLevel::ERROR:
            levelStr = "ERROR: ";
            break;
        case LogLevel::WARNING:
            levelStr = "WARNING: ";
            break;
        case LogLevel::INFO:
            levelStr = "INFO: ";
            break;
        default:
            break;
        }

        // Get local time
        time_t now = time(nullptr);
        struct tm timeInfo;
        char timeBuffer[TIME_LEN];
#ifdef _WIN32
        localtime_s(&timeInfo, &now);
#else
        localtime_r(&now, &timeInfo, );
#endif
        strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", &timeInfo);
        string strMessage = timeBuffer;
        if (fileName != nullptr && line > 0)
        {
            strMessage += ", " + string(fileName) + ", " + to_string(line);
        }
        strMessage += " [" + levelStr + "] " + message;

        // Print the message or write the message to log file
        cout << strMessage << endl;
        if (logFile.is_open())
        {
            logFile << strMessage << endl;
        }
    }

private:
    Logger() = default;
    ~Logger()
    {
        CloseLogFile();
    }
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger& operator=(Logger&&) = delete;

    ofstream logFile;
};

#endif // LOGGER_H

