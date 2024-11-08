#include <QCoreApplication>
#include <QString>
#include <QTimer>
#include "HttpAccess.h"
#include "RETool.h"
#include "CSVTool.h"
#include "ICPlogger.h"
#include "Settings.h"

void Exit()
{
    QCoreApplication::exit();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QObject::connect(&a, &QCoreApplication::aboutToQuit, &Settings::GetInstance(), &Settings::SyncSettings);
    QVariant regularExpressContent = Settings::GetInstance().Getvalue("RegularExpression");
    if (regularExpressContent.isValid()) {
        QString reContent = regularExpressContent.toString();
        ICPlogger::GetInstance().LogInfo("Web page content retrieved from settings: " + reContent);
    } else
    {
        ICPlogger::GetInstance().LogError("Failed to retrieve web page content from settings.");
    }
    Settings::GetInstance().SetValue("LastPage", "https://www.sina.com.cn");

    HttpAccess httpAccess;
    RETool reTool(regularExpressContent.toString());

    CSVTool csvTool("spyder.csv");
    QVector<QString> headers = {"title", "url"};

    QObject::connect(&httpAccess, &HttpAccess::finished, [&](const QString& data){
        QVector<QString> matchResults = reTool.Match(data);
        bool isWriteOk = csvTool.WriteCSV(headers, matchResults, QStringConverter::Utf8);
        if (isWriteOk) {
            ICPlogger::GetInstance().LogInfo("Spyder info has been successfully written to csv file.");
        }else {
            ICPlogger::GetInstance().LogError("Failed to write spyder info to CSV file.");
        }

        QVector<QString> readData = csvTool.readCSV();
        if(matchResults == readData) {
            ICPlogger::GetInstance().LogInfo("Data read from the csv file matches the original test data.");
        }
        else {
            ICPlogger::GetInstance().LogError("Data read from the CSV file does not match the original test data");
        }

        Settings::GetInstance().SyncSettings();
        QTimer::singleShot(0, &Exit);
    });

    QObject::connect(&httpAccess, &HttpAccess::error, [](const QString& errorString){
        qDebug() << errorString;
        QTimer::singleShot(0, &Exit);
    });

    httpAccess.Get(QUrl("https://www.baidu.com"));
    return a.exec();
}

