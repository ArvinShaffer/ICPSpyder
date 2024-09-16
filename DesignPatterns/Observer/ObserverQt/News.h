#ifndef NEWS_H
#define NEWS_H
#include <QObject>

class News:public QObject {
    Q_OBJECT

private:
    QString m_name;
signals:
    void news(const QString& name)const;
public:
    News(const QString& name) : m_name(name){}
    void send() const
    {
        emit news(m_name);
    }
};

#endif // NEWS_H
