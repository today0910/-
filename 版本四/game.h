#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QEvent>
#include <QDebug>
#include <QTimerEvent>
#include <QKeyEvent>
#include "windows.h"
#include <QString>
#include"shadewindow.h"
#include"pause.h"
#include"mypushbutton.h"

namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    int id1;
    double x[2];
        double y[2];
        double vx[2];
        double vy[2];
        double ay[2];
        double maxx[2];
        double maxy[2];
        double minx[2];
        double miny[2];
    int rednumber,bluenumber;
    bool redget[4];
    bool blueget[4];
    int move_;
    bool getMaxAndMin(int,int,int);
    void reset();
    ~game();
    QTimer* m_gameTimer;  // 游戏计时器
    Pause* pause=NULL;
    MyPushButton *pausebtn;
protected:
    void timerEvent(QTimerEvent *event);
private:
    Ui::game *ui;
    int m_elapsedSeconds; // 已过去的秒数
    shadewindow*shade=NULL;


signals:
    void winend1();
    void loseend();
    void winend2();
    void winend3();
    void winend4();
    void winend5();
    void pause_();
private slots:
    void checkTime();  // 检查时间槽函数

};


#endif // GAME_H
