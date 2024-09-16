#ifndef READER_H
#define READER_H
#include <QObject>
#include <QDebug>

class Reader:public QObject
{
    Q_OBJECT
public:
    Reader(int id):m_id(id) {}

public slots:
    void ReceiveInfo(const QString& info) const
    {
        qDebug() << "From " << m_id << " Get News: " << info;
    }
private:
    int m_id;
};

#endif // READER_H
