#ifndef HTTPACCESS_H
#define HTTPACCESS_H
#include <QObject>
#include <QtNetwork/QtNetwork>

static const QString g_UserAgent[] = {"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36 OPR/26.0.1656.60",
                                      "Opera/8.0 (Windows NT 5.1; U; en)",
                                      "Mozilla/5.0 (Windows NT 5.1; U; en; rv:1.8.1) Gecko/20061208 Firefox/2.0.0 Opera 9.50",
                                      "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; en) Opera 9.50",
                                      "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:34.0) Gecko/20100101 Firefox/34.0"};


class HttpAccess : public QObject
{
    Q_OBJECT
public:
    explicit HttpAccess(QObject *parent = nullptr);
    HttpAccess(const HttpAccess *other) = delete;
    HttpAccess(const HttpAccess &&other) = delete;

    HttpAccess& operator=(const HttpAccess& other)=delete;
    HttpAccess& operator=(const HttpAccess&& other)=delete;
    virtual ~HttpAccess();
    void Get(const QUrl& url);

signals:
    void finished(const QString& data);
    void error(const QString& errorString);
private:
    QNetworkAccessManager m_manager;
    void HandleError(int statusCode);
};

#endif // HTTPACCESS_H
