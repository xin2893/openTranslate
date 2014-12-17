#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <QObject>
#include <QtNetwork>
#include <QDebug>


#include "baiduapidictresult.h"


class Translate : public QObject
{
    Q_OBJECT
    Q_PROPERTY(BaiduAPIDictResult *result READ result WRITE setResult NOTIFY resultChanged)
public:
    explicit Translate(QObject *parent = 0);
    BaiduAPIDictResult *result() const;
    void setResult(BaiduAPIDictResult *res);

    void startRequest(QUrl url);
    Q_INVOKABLE void dictSendWord(QString word, QString from, QString to);

signals:
    void dataPostReady(const QString &rtext);
    void resultChanged();

public slots:
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64 bytesRead, qint64 totalBytes);

private:
    bool httpRequestAborted;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;

    BaiduAPIDictResult *baidu;
};

#endif // TRANSLATE_H
