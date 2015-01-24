#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <QObject>
#include <QtNetwork>
#include <QDebug>


#include "baiduapidictresult.h"


#define G_TRANSLATE 1
#define G_DICTORY 0


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
    Q_INVOKABLE void transSendParagraph(QString word, QString from, QString to);
signals:
    void dataPostReady(const QString &rtext);
    void resultChanged();

public slots:
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64 bytesRead, qint64 totalBytes);
    void setTranslateFlag(void){
        //qDebug() <<"trans";
        trflag = G_TRANSLATE;
    }
    void setDictoryFlag(void){ trflag = G_DICTORY;}
    bool checkTrFlag(void){
        if(trflag) return true;
        return false;
    }

private:
    bool httpRequestAborted;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;

    qint64 trflag;
    BaiduAPIDictResult *baidu;
};

#endif // TRANSLATE_H
