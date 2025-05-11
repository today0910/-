#include "winend5.h"
#include "ui_winend5.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
winend5::winend5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winend5)
{
    ui->setupUi(this);
    this->setFixedSize(680,367);
    this->setWindowTitle("游戏成功");
    //this->setWindowModality(Qt::ApplicationModal);
    this->setWindowOpacity(0.95); //窗口整体透明度
    this->setWindowFlags(Qt::FramelessWindowHint); //设置无边框风格
    this->setAttribute(Qt::WA_TranslucentBackground); //设置背景透明，允许鼠标穿透
    MyPushButton *continuebtn5=new MyPushButton(":/image/continue_button.png",1,1);
    continuebtn5->setParent(this);
    continuebtn5->move(225,225);
    connect(continuebtn5,&MyPushButton::clicked,[=]{
        continuebtn5->zoom1();
        continuebtn5->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            emit this->CloseWinend5();
        });
    });
}

winend5::~winend5()
{
    delete ui;
}
void winend5::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/win5.png");
    painter.drawPixmap(0,0,680,367,pix);
}

