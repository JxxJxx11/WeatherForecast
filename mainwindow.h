#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QList>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QByteArray>
#include "WeatherTool.h"
#include "weatherdata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

private slots:
    void slot_exitApp();
    void replayFinished(QNetworkReply *reply);

    void on_refreshButton_clicked();

    void on_searchBt_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual bool eventFilter(QObject* watched, QEvent* event);

protected:

    void contextMenuEvent(QContextMenuEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    static const QPoint sun[2];
    static const QRect sunRizeSet[2];
    static const QRect rect[2];

    Ui::MainWindow *ui;
    QMenu *exitMenu; //右键退出菜单
    QAction *exitAct; //退出的行为
    QPoint mPos; //窗口移动需要用的点
    //UI
    QList<QLabel *> forecast_week_list; //星期
    QList<QLabel *> forecast_date_list; //日期
    QList<QLabel *> forecast_aqi_list; //天气指数
    QList<QLabel *> forecast_type_list; //天气
    QList<QLabel *> forecast_typeIco_list; //天气图标
    QList<QLabel *> forecast_high_list; //高温
    QList<QLabel *> forecast_low_list; //低温
    //网络请求
    QNetworkAccessManager *manager;
    QString url; //接口链接
    QString city; //访问的城市
    QString cityTmp; //临时存放城市变量
    WeatherTool tool; //天气工具对象
    //本地数据
    Today today;
    Forecast forecast[6];

    QTimer *sunTimer;

    //函数
    void getWeatherInfo(QNetworkAccessManager *manager);
    void parseJson(QByteArray& bytes);
    void setLabelContent();
    void paintSunRiseSet();
    void paintCurve();
};
#endif // MAINWINDOW_H
