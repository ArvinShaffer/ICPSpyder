#include "HttpAccess.h"
#include "ICPlogger.h"

HttpAccess::HttpAccess(QObject *parent) : QObject(parent) {}

void HttpAccess::Get(const QUrl& url)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, g_UserAgent[0]);
    QNetworkReply *reply = m_manager.get(request);

    QObject::connect(reply, &QNetworkReply::finished, [this, reply]() {
        //qDebug() << reply->error();
        if(reply->error() == QNetworkReply::NoError)
        {
            QByteArray data = reply->readAll();
            QString htmlContent = QString::fromUtf8(data);
            emit finished(htmlContent);
        }
        else
        {
            int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            HandleError(statusCode);
            emit error(reply->errorString());
        }
    });
}

void HttpAccess::HandleError(int statusCode)
{
    ICPlogger::GetInstance().LogError(QString::number(statusCode));
}

HttpAccess::~HttpAccess()
{

}
