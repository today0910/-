#include "startwindow.h"
#include "ui_startwindow.h"
#include<QPainter>
#include<mypushbutton.h>
#include<QDebug>
#include<QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowIcon(QPixmap(":/image/min.jpg"));
    this->setWindowTitle("森林冰火人");

    //设置遮罩
    shade = new shadewindow;
    //设置窗口无边框且为独立窗口
    shade->setParent(this,Qt::FramelessWindowHint | Qt::Window);
    //shade->setGeometry(0, 0, 1, 1);
    //shade->hide();

    //开始按钮
    MyPushButton *startbtn=new MyPushButton(":/image/play2.png",0.5,0.5);
    startbtn->setParent(this);
    startbtn->move(this->width()*0.5-startbtn->width()*0.5,250);

    gam=new game;

    connect(startbtn,&MyPushButton::clicked,[=](){

        startbtn->zoom1();
        startbtn->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            gam->reset();
            this->hide();
            gam->show();
        });
    });
    //set button
    s=new set;
    MyPushButton *setbtn=new MyPushButton(":/image/set-removebg-preview.png",0.15,0.15);
    setbtn->setParent(this);
    setbtn->move(this->width()-190,420);
    connect(s, &set::stopMusic, this, &MainWindow::handleStopMusic);
    connect(s, &set::playMusic, this, &MainWindow::handlePlayMusic);
    connect(s,&set::setBack,this,[=](){
        s->hide();
        shade->hide();
    });
    connect(setbtn,&MyPushButton::clicked,[=](){
        setbtn->zoom1();
        setbtn->zoom2();
        s->show();
        shade->show();
    });

    //questionButton
    m=new more;
    MyPushButton *questionbtn=new MyPushButton(":/image/more-removebg-preview.png",0.15,0.15);
    questionbtn->setParent(this);
    questionbtn->move(-110,375);
    connect(m,&more::moreBack,this,[=](){
        m->hide();
        shade->hide();
    });
    connect(questionbtn,&MyPushButton::clicked,[=](){
        questionbtn->zoom1();
        questionbtn->zoom2();
        m->show();
        shade->show();
    });
    //win1
    win1=new winend;
    connect(gam,&game::winend1,[=](){
        shade->show();
        win1->show();
    });
    connect(win1,&winend::CloseWinend,[=](){
       gam->reset();
       gam->hide();
       win1->close();
       shade->hide();
       this->show();
    });
    //win2
    win2=new winend2;
    connect(gam,&game::winend2,[=](){
        shade->show();
        win2->show();
    });
    connect(win2,&winend2::CloseWinend2,[=](){
       gam->reset();
       gam->hide();
       win2->close();
       shade->hide();
       this->show();
    });
    //win3
    win3=new winend3;
    connect(gam,&game::winend3,[=](){
        shade->show();
        win3->show();
    });
    connect(win3,&winend3::CloseWinend3,[=](){
        gam->reset();
        gam->hide();
        win3->close();
        shade->hide();
        this->show();
    });
    //win4
    win4=new winend4;
    connect(gam,&game::winend4,[=](){
        shade->show();
        win4->show();
    });
    connect(win4,&winend4::CloseWinend4,[=](){
        gam->reset();
        gam->hide();
        win4->close();
        shade->hide();
        this->show();
    });
    //win5
    win5=new winend5;
    connect(gam,&game::winend5,[=](){
        shade->show();
        win5->show();
    });
    connect(win5,&winend5::CloseWinend5,[=](){
        gam->reset();
        gam->hide();
        win5->close();
        shade->hide();
        this->show();
    });
    //lose
    lose=new loseend;
    connect(gam,&game::loseend,[=](){
        //qDebug()<<"lose";
        shade->show();
        lose->show();
    });
    connect(lose,&loseend::menus,[=](){
       gam->reset();
       gam->hide();
       lose->hide();
       shade->hide();
       this->show();
    });
    connect(lose,&loseend::retrys,[=](){
       gam->reset();
       lose->hide();
       shade->hide();
    });
    //背景音乐
    bgm = new QSoundEffect(this);
    bgm->setSource(QUrl("qrc:/image/Music.wav"));
    bgm->setLoopCount(QSoundEffect::Infinite);  // 无限循环
    bgm->setVolume(0.7f);  // 音量范围0.0-1.0
    bgm->play();

}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/start.png");
    painter.drawPixmap(0,0,pix);
}
// 处理停止音乐的槽函数
void MainWindow::handleStopMusic()
{
    if (bgm->isPlaying()) {
        bgm->stop();
    }
}

// 处理播放音乐的槽函数
void MainWindow::handlePlayMusic()
{
    if (!bgm->isPlaying()) {
        bgm->play();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

