#include "set.h"
#include<QPainter>

#include<QDebug>
#include<QPoint>
#include<QMouseEvent>
#include<QTimer>
#include"startwindow.h"
set::set(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,700);
    this->setWindowTitle("设置");
    this->setWindowModality(Qt::ApplicationModal);
    //窗口整体透明度，0-1 从全透明到不透明
    this->setWindowOpacity(1);
    //设置无边框风格
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置背景透明，允许鼠标穿透
    this->setAttribute(Qt::WA_TranslucentBackground);
    //返回按钮
    MyPushButton *backbtn=new MyPushButton(":/image/back_.png",0.5,0.5);
    backbtn->setParent(this);
    backbtn->move(this->width()*0.5-125,415);

    connect(backbtn,&MyPushButton::clicked,[=]{
        backbtn->zoom1();
        backbtn->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            emit this->setBack();
        });

    });
    //音乐按钮
    musicbtn=new MyPushButton(":/image/music.png",0.4,0.4);
    musicbtn->setParent(this);
    //设置按钮位置
    musicbtn->move(this->width()*0.5-100,230);

    connect(musicbtn,&MyPushButton::clicked,[=]()mutable{
        musicbtn->zoom1();
        musicbtn->zoom2();
        // 切换音乐状态
        musicPlaying = !musicPlaying;

        if (musicPlaying) {
            emit playMusic();  // 发射播放音乐信号
            musicbtn->setIcon(QIcon(":/image/music.png"));
        } else {
            emit stopMusic();  // 发射停止音乐信号
            musicbtn->setIcon(QIcon(":/image/music_close.png"));
        }
    });
}
void set::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/set2.png");
    painter.drawPixmap(210,210,600,326,pix);
}

