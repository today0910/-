#include "loseend.h"
#include "ui_loseend.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
loseend::loseend(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loseend)
{
    ui->setupUi(this);
    this->setWindowTitle("游戏失败");
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
    MyPushButton *retrybtn=new MyPushButton(":/image/retry_button.png",1,1);
    retrybtn->setParent(this);
    retrybtn->move(380,240);
    connect(retrybtn,&MyPushButton::clicked,[=]{
        retrybtn->zoom1();
        retrybtn->zoom2();
        //延时
        QTimer::singleShot(150,this,[=](){
            emit this->retrys();
        });
    });
}

loseend::~loseend()
{
    delete ui;
}
void loseend::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    //加载背景图片并添加错误处理
    if (!pix.load(":/image/loseend.png")) {
        qWarning() << "Failed to load loseend background image!";
    }
    painter.drawPixmap(0,0,652,382,pix);
}
