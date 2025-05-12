#include "winend.h"
#include "ui_winend.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
winend::winend(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winend)
{
    ui->setupUi(this);
    this->setFixedSize(680,367);
    this->setWindowTitle("游戏成功");
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowOpacity(0.95); //窗口整体透明度
    this->setWindowFlags(Qt::FramelessWindowHint); //设置无边框风格
    this->setAttribute(Qt::WA_TranslucentBackground); //设置背景透明，允许鼠标穿透
    MyPushButton *continuebtn=new MyPushButton(":/image/continue_button.png",1,1);
    continuebtn->setParent(this);
    continuebtn->move(225,225);
    connect(continuebtn,&MyPushButton::clicked,[=]{
        continuebtn->zoom1();
        continuebtn->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            emit this->CloseWinend();
        });
    });
}

winend::~winend()
{
    delete ui;
}
void winend::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/win1.png");
    painter.drawPixmap(0,0,680,367,pix);
}
