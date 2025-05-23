#include "more.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QDebug>
#include<QTimer>
more::more(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,540);
    this->setWindowTitle("游戏设置");
    this->setWindowModality(Qt::ApplicationModal);
    //窗口整体透明度，0-0.95
    this->setWindowOpacity(0.95);
    //设置无边框风格
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置背景透明，允许鼠标穿透
    this->setAttribute(Qt::WA_TranslucentBackground);
    //返回按钮
    MyPushButton *backbtn=new MyPushButton(":/image/back.png",0.5,0.5);
    backbtn->setParent(this);
    backbtn->move(this->width()*0.5-120,235);

    connect(backbtn,&MyPushButton::clicked,[=]{
        backbtn->zoom1();
        backbtn->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            emit this->moreBack();
        });
    });
}
void more::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/d.png");
    painter.drawPixmap(200,100,600,381,pix);
}
