#ifndef CSVTOOL_H
#define CSVTOOL_H
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <stdexcept>
#include <QTextCodec>
#include <QByteArray>

class CSVTool
{
public:
    explicit CSVTool(const QString& fileName):m_fileName(fileName){};
    bool WriteCSV(const QVector<QString>& header, const QVector<QString>& keyValuePair, QStringConverter::Encoding codec);

    QVector<QString> readCSV();

private:
    QString m_fileName;

};

#endif // CSVTOOL_H
