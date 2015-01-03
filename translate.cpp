#include "translate.h"
#include "global.h"

Translate::Translate(QObject *parent) :
    QObject(parent)
{
    baidu = NULL;
    //connect(this, SIGNAL(dataPostReady(QString&)), this, SLOT(deleteLater()));
}


//qml method
void Translate::dictSendWord(QString word, QString from, QString to)
{
    //create url
    //QUrl url;
    QString surl(tr("http://openapi.baidu.com/public/2.0/translate/dict/simple?client_id=%1&q=%2&from=%3&to=%4")\
                 .arg(OT_BAIDU_API_KEY).arg(word).arg(from).arg(to));
    qDebug() << surl;
    startRequest(QUrl(surl));

}

void Translate::transSendParagraph(QString word, QString from, QString to)
{
    QString surl(tr("http://openapi.baidu.com/public/2.0/bmt/translate?client_id=%1&q=%2&from=%3&to=%4")\
                 .arg(OT_BAIDU_API_KEY).arg(word).arg("auto").arg("auto"));
    qDebug() << surl;
    startRequest(QUrl(surl));
}


void Translate::startRequest(QUrl url)
{
    reply = qnam.get(QNetworkRequest(url));
    connect(reply, SIGNAL(finished()),
            this, SLOT(httpFinished()));
    connect(reply, SIGNAL(readyRead()),
            this, SLOT(httpReadyRead()));
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(updateDataReadProgress(qint64,qint64)));
}


void Translate::httpFinished()
{
    if (httpRequestAborted) {

        reply->deleteLater();
        //progressDialog->hide();
        return;
    }

    //progressDialog->hide();
    //file->flush();
    //file->close();


    QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if (reply->error()) {
#if 0
        file->remove();
        QMessageBox::information(this, tr("HTTP"),
                                 tr("Download failed: %1.")
                                 .arg(reply->errorString()));
        downloadButton->setEnabled(true);
#endif
    } else if (!redirectionTarget.isNull()) {
#if 0
        QUrl newUrl = url.resolved(redirectionTarget.toUrl());
        if (QMessageBox::question(this, tr("HTTP"),
                                  tr("Redirect to %1 ?").arg(newUrl.toString()),
                                  QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
            url = newUrl;
            reply->deleteLater();
            file->open(QIODevice::WriteOnly);
            file->resize(0);
            startRequest(url);
            return;
        }
#endif
    } else {
        //QString fileName = QFileInfo(QUrl(urlLineEdit->text()).path()).fileName();
        //statusLabel->setText(tr("Downloaded %1 to %2.").arg(fileName).arg(QDir::currentPath()));

    }

    reply->deleteLater();
    reply = 0;
    //delete file;
}
/*
void Translate::readJsonObject(QJsonObject &obj)
{

}
*/


void Translate::httpReadyRead()
{
    // this slot gets called every time the QNetworkReply has new data.
    // We read all of its new data and write it into the file.
    // That way we use less RAM than when reading it at the finished()
    // signal of the QNetworkReply
    //if (file)
        //file->write(reply->readAll());
    QByteArray rawdata(reply->readAll());
    QString data(rawdata);
    if(NULL == baidu){
        qDebug() << "result is null";
        //result = new BaiduAPIDictResult;
    }else{
        //delete result;
        //result = new BaiduAPIDictResult;
    }
    //setRootContextBaiDuAPI(result);
    baidu->initBaiDuData();
    if(!checkTrFlag())
        baidu->parseBaiDuJsonData(rawdata);
    else
        baidu->parseBaiDuTranJsonData(rawdata);
    //qDebug() << data;
    emit dataPostReady(data);
}

void Translate::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
    if (httpRequestAborted)
        return;

    //progressDialog->setMaximum(totalBytes);
    //progressDialog->setValue(bytesRead);
}

BaiduAPIDictResult * Translate::result() const
{
    return baidu;
}

void Translate::setResult(BaiduAPIDictResult *res)
{
    baidu = res;
}

