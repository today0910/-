#include "pause.h"
#include "ui_pause.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
Pause::Pause(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pause)
{
    ui->setupUi(this);
    this->setWindowTitle("游戏暂停");
    this->setFixedSize(652,382);

    //窗口整体透明度，0-0.95
    this->setWindowOpacity(0.95);
    //设置无边框风格
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置背景透明，允许鼠标穿透
    this->setAttribute(Qt::WA_TranslucentBackground);
    MyPushButton *menubtn=new MyPushButton(":/image/menu_button.png",1,1);
    menubtn->setParent(this);
    menubtn->move(120,240);
    //菜单按钮点击事件
    connect(menubtn,&MyPushButton::clicked,[=]{
        menubtn->zoom1();
        menubtn->zoom2();
        //延时
        QTimer::singleShot(150,this,[=](){
            emit this->menus();
        });
    });
    MyPushButton *Continue=new MyPushButton(":/image/continue_button.png",1,1);
    Continue->setParent(this);
    Continue->move(380,240);
    connect(Continue,&MyPushButton::clicked,[=]{
        Continue->zoom1();
        Continue->zoom2();
        //延时
        QTimer::singleShot(150,this,[=](){
            emit this->continue_();
        });
    });
}

Pause::~Pause()
{
    delete ui;
}
void Pause::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    //加载背景图片并添加错误处理
    pix.load(":/image/c.png");
    painter.drawPixmap(0,0,652,382,pix);
}
