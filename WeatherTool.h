#ifndef WEATHERTOOL_H
#define WEATHERTOOL_H
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <map>
#include <QFile>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>

class WeatherTool{
public:
    WeatherTool(){
        QDir *dir = new QDir(QDir::currentPath());
        dir->cdUp();
        // QString fileName = QCoreApplication::applicationDirPath();
        QString fileName =  dir->absolutePath() + "/" + QCoreApplication::applicationName();
        fileName += "/citycode-2019-08-23.json";
        // qDebug() << fileName;
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray json = file.readAll();
        file.close();
        QJsonParseError err;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(json, &err);
        QJsonArray citys = jsonDoc.array();
        for(int i=0; i<citys.size(); ++i){
            QString code = citys.at(i).toObject().value("city_code").toString();
            QString city = citys.at(i).toObject().value("city_name").toString();
            if(code.size() > 0){
                m_mapCity2Code.insert(std::pair<QString, QString>(city, code));
            }

        }
    }

    QString operator[](const QString& city){
        std::map<QString, QString>::iterator it = m_mapCity2Code.find(city);
        if(it == m_mapCity2Code.end()){
            it = m_mapCity2Code.find(city + u8"市");
        }
        if(it != m_mapCity2Code.end()){
            return it->second;
        }
        return "000000000";
    }

private:
    std::map<QString, QString> m_mapCity2Code;
};

#endif // WEATHERTOOL_H
