#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>
#include <QWidget>


class Today{
public:
    Today();
    Today& operator=(const QJsonObject& obj);
    QString date;
    QString wendu;
    QString city;
    QString shidu;
    QString pm25;
    QString quality;
    QString ganmao;
    QString fx;
    QString fl;
    QString type;
    QString sunrise;
    QString sunset;
    QString notice;
};

class Forecast{
public:
    Forecast();
    Forecast& operator=(const QJsonObject& obj);
    QString date;
    QString week;
    QString high;
    QString low;
    QString aqi;
    QString type;
};

#endif // WEATHERDATA_H
