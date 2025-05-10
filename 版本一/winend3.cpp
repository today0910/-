#include "winend3.h"
#include "ui_winend3.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
winend3::winend3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winend3)
{
    ui->setupUi(this);
    this->setFixedSize(680,367);
    this->setWindowTitle("游戏成功");
    //this->setWindowModality(Qt::ApplicationModal);
    this->setWindowOpacity(0.95); //窗口整体透明度
    this->setWindowFlags(Qt::FramelessWindowHint); //设置无边框风格
    this->setAttribute(Qt::WA_TranslucentBackground); //设置背景透明，允许鼠标穿透
    MyPushButton *continuebtn3=new MyPushButton(":/image/continue_button.png",1,1);
    continuebtn3->setParent(this);
    continuebtn3->move(225,225);
    connect(continuebtn3,&MyPushButton::clicked,[=]{
        continuebtn3->zoom1();
        continuebtn3->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            emit this->CloseWinend3();
        });
    });
}

winend3::~winend3()
{
    delete ui;
}
void winend3::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/win3.png");
    painter.drawPixmap(0,0,680,367,pix);
}

