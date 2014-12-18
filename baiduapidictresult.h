#ifndef BAIDUAPIDICTRESULT_H
#define BAIDUAPIDICTRESULT_H

#include <QObject>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

class BaiduAPIDictResult : public QObject
{
    Q_OBJECT
public:
    explicit BaiduAPIDictResult(QObject *parent = 0);
    ~BaiduAPIDictResult(){}

    void bd_set_errno(qint64 err) {errno = err;}
    void bd_set_word_name(QString name){word_name = name;}
    void bd_set_from(QString f){from = f;}
    void bd_set_to(QString t){to = t;}
    void bd_set_ph_am(QString am){ph_am = am;}
    void bd_set_ph_en(QString en){ph_en = en;}
    void bd_set_part_num(qint64 n){part_num = n;}
    void bd_set_parts(QString s){parts << s;}
    void bd_set_means_num(qint64 n, int j);
    void bd_set_means(QStringList sl, int i);

    void initBaiDuData(void);
    void parseBaiDuJsonData(QByteArray text);
    void readBaiDuJsonSymbolsArray(QJsonObject &obj);


public slots:
    qint64 bd_get_errno(){ return errno;}
    QString bd_get_word_name(){return word_name;}
    QString bd_get_from(){return from;}
    QString bd_get_to(){return to;}
    QString bd_get_ph_am(){return ph_am;}
    QString bd_get_ph_en(){return ph_en;}
    qint64 bd_get_part_num(){return part_num;}
    QString bd_get_parts(qint64 i){
        return parts[i];
    }
    QString bd_ddd(){return parts[0];}

    qint64 bd_get_means_num(qint64 pindex){return means_num[pindex];}
    QString bd_get_means(qint64 pindex, qint64 mindex){
        //qDebug() << "pindex:" << pindex << " mindex:" << mindex;
        //qDebug() << "size:" << means.size();
        return means[pindex][mindex];
    }
private:
    qint64  errno;
    QString from;
    QString to;
    QString word_name;
    QString ph_am;
    QString ph_en;
    qint64 part_num;
    QStringList parts;
    QList<qint64> means_num;
    QList<QStringList> means;
};

#endif // BAIDUAPIDICTRESULT_H
