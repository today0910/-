#include "winend4.h"
#include "ui_winend4.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
winend4::winend4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winend4)
{
    ui->setupUi(this);
    this->setFixedSize(680,367);
    this->setWindowTitle("游戏成功");
    //this->setWindowModality(Qt::ApplicationModal);
    this->setWindowOpacity(0.95); //窗口整体透明度
    this->setWindowFlags(Qt::FramelessWindowHint); //设置无边框风格
    this->setAttribute(Qt::WA_TranslucentBackground); //设置背景透明，允许鼠标穿透
    MyPushButton *continuebtn4=new MyPushButton(":/image/continue_button.png",1,1);
    continuebtn4->setParent(this);
    continuebtn4->move(225,225);
    connect(continuebtn4,&MyPushButton::clicked,[=]{
        continuebtn4->zoom1();
        continuebtn4->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            emit this->CloseWinend4();
        });
    });
}

winend4::~winend4()
{
    delete ui;
}
void winend4::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/win4.png");
    painter.drawPixmap(0,0,680,367,pix);
}

