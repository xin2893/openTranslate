#include "baiduapidictresult.h"

BaiduAPIDictResult::BaiduAPIDictResult(QObject *parent) :
    QObject(parent)
{
    initBaiDuData();
}

void BaiduAPIDictResult::readBaiDuJsonSymbolsArray(QJsonObject &obj)
{
    if(obj["symbols"].isArray()){
        QJsonArray symarr = obj.take("symbols").toArray();
        for (int i = 0; i < symarr.size(); ++i) {
            if(symarr[i].isObject()){
                QJsonObject symobj = symarr[i].toObject();
                qDebug() << symobj["ph_am"].toString();
                qDebug() << symobj["ph_en"].toString();
                bd_set_ph_am(symobj["ph_am"].toString());
                bd_set_ph_en(symobj["ph_en"].toString());
                QJsonArray parts = symobj["parts"].toArray();
                bd_set_part_num(parts.size());
                for(int j =0; j < parts.size(); j++){
                    if(parts[j].isObject()){
                        QJsonObject partsobj = parts[j].toObject();
                        qDebug() << partsobj["part"].toString();
                        bd_set_parts(partsobj["part"].toString());
                        if(partsobj["means"].isArray()){
                            QJsonArray means = partsobj["means"].toArray();
                            bd_set_means_num(means.size(),j);
                            QStringList sl;
                            for(int m = 0;m < means.size(); m++){
                                //qDebug() << means[m].toString();
                                //result->bd_set_means();
                                sl << means[m].toString();
                            }
                            bd_set_means(sl,j);
                            qDebug() << "sl size: " << sl.size();
                            //qDebug() << sl[0] << "--" << sl[1] << sl[2];

                        }
                    }
                }
            }
        }
    }
    //qDebug() << "means[0][0]" << bd_get_means(0,0);
}


//dictory data parse
void BaiduAPIDictResult::parseBaiDuJsonData(QByteArray text)
{
    qDebug() << "ddd:" << text;
    QJsonParseError perr;
    QJsonDocument doc = QJsonDocument::fromJson(text, &perr);
    if(perr.error == QJsonParseError::NoError){
        qDebug() << "noerror";
    }else{
        qDebug() << perr.errorString();
    }
    //QJsonArray json = doc.array();
    if(doc.isObject()){
        qDebug() << "doc is obj";
        QJsonObject js = doc.object();
        if(js.contains("errno")){
            //result.errno = js.take("errno").toInt();
            bd_set_errno(js["errno"].toInt());
            qDebug() << "result.errno:" << bd_get_errno();
        }
        if(js.contains("data")){
            qDebug() << "data";
            if(js["data"].isObject()){
                //qDebug() << "sss";
                QJsonObject data = js.take("data").toObject();
                if(data.contains("word_name")){
                    bd_set_word_name(data["word_name"].toString());
                    //result.word_name = data.take("word_name").toString();
                    qDebug() << "result.word_name" << bd_get_word_name();
                }
                if(data.contains("symbols")){
                    readBaiDuJsonSymbolsArray(data);
                }
            }
        }
        if(js.contains("from")){
            //qDebug() << "contains from";
            QJsonValue value = js.take("from");
            if(value.isString()){
                bd_set_from(value.toString());
                qDebug() << value.toString();
            }
        }
        if(js.contains("to")){
            bd_set_to(js["to"].toString());
            qDebug() << js["to"].toString();
        }
    }
    if(doc.isNull()){
        qDebug() << "doc is null";
    }
    if(doc.isEmpty()){
        qDebug() << "doc is empty";
    }
    if(doc.isArray()){
        qDebug() << "doc is array";

    }

}


//translate array parse
void BaiduAPIDictResult::readBaiDuTrJsonArray(QJsonArray &arr)
{
    trans_num = arr.size();
    for(int i = 0; i < arr.size(); i++){
        QJsonObject obj = arr[i].toObject();
        if(obj.contains("src")){
            bd_set_src(obj["src"].toString(), i);
            qDebug() << get_trans_src(i);
        }
        if(obj.contains("dst")){
            bd_set_dst(obj["dst"].toString(),i);
            qDebug() << get_trans_dst(i);
        }
    }
    //qDebug() << "means[0][0]" << bd_get_means(0,0);
}

//translate data parse
void BaiduAPIDictResult::parseBaiDuTranJsonData(QByteArray text)
{
    qDebug() << "ddd:" << text;
    QJsonParseError perr;
    QJsonDocument doc = QJsonDocument::fromJson(text, &perr);
    if(perr.error == QJsonParseError::NoError){
        qDebug() << "noerror";
    }else{
        qDebug() << perr.errorString();
    }
    //QJsonArray json = doc.array();
    if(doc.isObject()){
        qDebug() << "doc is obj";
        QJsonObject js = doc.object();
        if(js.contains("errno")){
            //result.errno = js.take("errno").toInt();
            bd_set_errno(js["errno"].toInt());
            err_msg = js["error_msg"].toString();
            qDebug() << "result.errno:" << bd_get_errno() << " msg: " << err_msg;
        }

        if(js.contains("from")){
            //qDebug() << "contains from";
            QJsonValue value = js.take("from");
            if(value.isString()){
                bd_set_from(value.toString());
                qDebug() << value.toString();
            }
        }
        if(js.contains("to")){
            bd_set_to(js["to"].toString());
            qDebug() << js["to"].toString();
        }

        if(js.contains("trans_result")){
            qDebug() << "trans_result";
            QJsonArray res = js["trans_result"].toArray();
            readBaiDuTrJsonArray(res);
        }
    }
    if(doc.isNull()){
        qDebug() << "doc is null";
    }
    if(doc.isEmpty()){
        qDebug() << "doc is empty";
    }
    if(doc.isArray()){
        qDebug() << "doc is array";

    }

}


void BaiduAPIDictResult::initBaiDuData(void)
{
    //QList<QStringList>::iterator end = means.end();
    qDebug() << means.size();
    for(int i=0; i < means.size(); i++){
        //QStringList::iterator end = means[i].end();
        for(int j=0; j < means[i].size(); j++){
            //qDebug() << "clear";
            means[i][j].clear();

        }
        //means[i].clear();
        //end = means.end();
        means[i].removeAt(i);
    }
    for(int i = 0; i < means_num.size(); i++)
        means_num.removeAt(i);
    for(int i =0;i< src.size();i++)
    {
        src.removeAt(i);
        dst.removeAt(i);
    }
    parts.clear();
    errno = 0;
    from.clear();
    to.clear();
    word_name.clear();
    ph_am.clear();
    ph_en.clear();
    part_num = 0;
    trans_num = 0;
}

void BaiduAPIDictResult::bd_set_means_num(qint64 n, int j)
{
    qDebug() << "nlength:" << means_num.length() << " i:" << j;
    if(means_num.isEmpty()|| (means_num.length() <= j))
        means_num << n;
    else{
        means_num.replace(j, n);
    }
}
void BaiduAPIDictResult::bd_set_means(QStringList sl, int i)
{
    qDebug() << "length:" << means.length() << " i:" << i;
    if(means.isEmpty() || (means.length() <= i))
        means << sl;
    else{
        qDebug() << "replace";
        means.replace(i, sl);
    }
}


void BaiduAPIDictResult::bd_set_src(QString s, qint64 i)
{
    qDebug() << "length:" << src.length() << " i:" << i;
    if(src.isEmpty() || (src.length() <= i))
        src << s;
    else{
        qDebug() << "replace";
        src.replace(i, s);
    }
}


void BaiduAPIDictResult::bd_set_dst(QString s, qint64 i)
{
    qDebug() << "length:" << dst.length() << " i:" << i;
    if(dst.isEmpty() || (dst.length() <= i))
        dst << s;
    else{
        qDebug() << "replace";
        dst.replace(i, s);

    }
}

//trans
qint64 BaiduAPIDictResult::get_trans_num(void)
{
    return trans_num;
}
QString BaiduAPIDictResult::get_trans_src(qint64 i)
{
    if(src.isEmpty())
        return NULL;
    return src[i];
}
QString BaiduAPIDictResult::get_trans_dst(qint64 i)
{
    if(dst.isEmpty())
        return NULL;
    return dst[i];
}



