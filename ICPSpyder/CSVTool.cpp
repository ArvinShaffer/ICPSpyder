#include "CSVTool.h"
#include "ICPlogger.h"

//bool CSVTool::WriteCSV(const QVector<QString>& headers, const QVector<QString>& keyValuePair, const char* codec)
bool CSVTool::WriteCSV(const QVector<QString>& headers, const QVector<QString>& keyValuePair, QStringConverter::Encoding codec)
{
    QFile file(m_fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        ICPlogger::GetInstance().LogError("Failed to open file for writing");
        return false;
    }
    //QTextCodec* codecc = QTextCodec::codecForName(codec);
    QTextStream outFile(&file);
    outFile.setEncoding(codec);

    try {
        outFile << headers[0] << " : " << headers[1];
        outFile << "\n";

        for (const QString& item : keyValuePair)
        {
            QStringList parts = item.split(" : ");
            if(parts.size() != 2)
            {
                ICPlogger::GetInstance().LogError("Data item format is invalid");
                throw std::runtime_error("Data item format is invalid");
            }
            outFile << parts[0] << " : " << parts[1];
            outFile << "\n";
        }
    } catch(const std::exception& ex) {
        ICPlogger::GetInstance().LogError(QString("Error while writing csv: ") + ex.what());
        file.close();
        return false;
    }
    file.close();
    return true;
}

QVector<QString> CSVTool::readCSV()
{
    QVector<QString> data;
    QFile file(m_fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ICPlogger::GetInstance().LogError("Failed to open file for reading.");
        return data;
    }
    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    QString headerLine = in.readLine();

    while(!in.atEnd())
    {
        QString dataLine = in.readLine();
        data.append(dataLine);
    }

    file.close();
    return data;
}

