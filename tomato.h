//
// Created by Administrator on 2017-5-16.
//

#ifndef TOMATO_H
#define TOMATO_H

//#include <string>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QByteArray>

//#include <QCheckBox>

//#include <QtWinExtras>
#include <QWinTaskbarButton>
#include <QWinTaskbarProgress>

//#include "config.h"

#include "lineedit.h"

//using namespace std;

class Tomato : public QWidget
{
    Q_OBJECT

public:
    Tomato(QWidget *parent=0);
    ~Tomato();

    //QString name = "番茄倒计时";
    //static name = "番茄倒计时";
    //static const QString name = "番茄倒计时";
    //const QString name = "番茄倒计时";

    //static QString name = "番茄倒计时";
    static QString name;

    //static int name = reinterpret_cast<int *>(QString("番茄倒计时"));
    //static int * name = reinterpret_cast<int *>(QString("番茄倒计时"));
    //static char * name = reinterpret_cast<char *>(QString("番茄倒计时"));
    //static char * name = reinterpret_cast<char *>("番茄倒计时");
    //static char * name = const_cast<char *>("番茄倒计时");
    //static char * name = static_cast<char *>("番茄倒计时");
    //static char * name = dynamic_cast<char *>("番茄倒计时");
    //E:\develop\QtProjects\TomatoDownWidgets\tomato.h:34: error: reinterpret_cast from type 'const char*' to type 'char*' casts away qualifiers
    //static char * name = reinterpret_cast<char *>();


    //static string name = "番茄倒计时";
    //static QByteArray name = QByteArray("番茄倒计时");

    bool initiated = false;

    int width = 500;
    int height = 300;

    int labelMinWidth = 50;
    int inputWidth = 40;
    int unitWidth = 25;

    int buttonWidth = 40;

    int itemHeight = 35;


    //int increase = 1;
    //bool increase = true;
    bool increase = false;
    //QCheckBox *increaseCheckBox;
    bool autoStart = true;
    //bool autoStart = false;

    // 任务栏图标进度条状态
    enum State {
        Normal = 1,
        Pause = 2,
        Stop = 3,
    };


    State state;
    //int state;

    // 计时状态
    enum CountState {
        CountInit = 10,
        CountInProgress = 11,
        CountPause = 12,
        CountStop = 13,
        CountBreak = 20,
        CountOvertime = 25,
    };

    CountState countState;

    /*
    init: 初始状态
    in progress: 进行中
    pause: 暂停
    stop: 停止
    break: 休息
    overtime: 超时
    */

    QPushButton *startButton;
    QPushButton *restartButton;
    QPushButton *continueButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QPushButton *breakButton;

    QPushButton *addButton;


    QMap<QString, QVariant> row;

    QLabel *progress;
    QLabel *to;

    //QPixmap *icon;
    //QPixmap icon;
    //QPainter *painter;
    qint64 lastOverlayMin = -1;

    LineEdit *inputTime;
    LineEdit *inputTipTime;
    LineEdit *inputBreakTime;


    //QHash<QString, QVariant> settings;
    //QHash<QString, QVariant> newSettings;
    //QHash<QString, QVariant> oldSettings;

    QMap<QString, QVariant> settings;
    QMap<QString, QVariant> newSettings;
    QMap<QString, QVariant> oldSettings;


    QHash<QString, bool> delayedActions; // 没有设置的值获取时是false
    QString keySaveSetting = "saveSetting";
    //QMap<QString, QString> fields;

    //QList<QString, QTimer *> timer;
    QHash<QString, QTimer *> timer;
    QHash<QString, qint64> timeConsumed;
    QString key = "one"; // 一条计时数据保存使用的key，便于以后扩展成多个计时

    void createTimer(QString timerKey);

    QWinTaskbarButton *taskbarButton;
    QWinTaskbarProgress *taskbarProgress;

    // 为了能看清任务栏图标上进度条的颜色，限制其最小值
    int progressMinValue = 50;

    void setOverlayIcon(int min);
    void setTaskbarProgress(State state, int value, int maxValue);
    //void setTaskbarProgress(int state, int value, int maxValue);

    QString paddingZero(qint64 i);
    qint64 getSecondsSince(QDateTime time);

    void setCountState(CountState state);

    QVBoxLayout *rightLayout;

    //void beginSaveSetting();

    void beginSaveCountMode();

public slots:
    void startCountDown();
    void restart();
    void continueCountDown();
    void pause();
    void stop();
    void startBreak();

    void countDown();


    //void increaseChanged(Qt::CheckState state);
    //void increaseChanged(int state);
    void countModeChanged(int state);
    void autoStartChanged(int state);


    void addButtonClicked();


    void endSaveSetting();
    void endSaveCountMode();



private:

    void setControlButtonVisibility();


    void beginSaveSetting();

};


#endif //TOMATO_H
