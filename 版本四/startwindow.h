#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include"game.h"
#include"set.h"
#include"more.h"
#include"winend.h"
#include"loseend.h"
#include"winend2.h"
#include"winend3.h"
#include"winend4.h"
#include"winend5.h"
#include"shadewindow.h"
#include <QSoundEffect>
#include"pause.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //画背景图
    void paintEvent(QPaintEvent*);

    game*gam=NULL;
    set*s=NULL;
    more*m=NULL;
    winend*win1=NULL;
    loseend*lose=NULL;
    winend2*win2=NULL;
    winend3*win3=NULL;
    winend4*win4=NULL;
    winend5*win5=NULL;
    shadewindow*shade=NULL;

private:
    Ui::MainWindow *ui;
    QSoundEffect *bgm;

private slots:
    void handleStopMusic();  // 槽函数：处理停止音乐
    void handlePlayMusic();  // 槽函数：处理播放音乐

};
#endif // STARTWINDOW_H
