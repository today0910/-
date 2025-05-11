#include "shadewindow.h"

shadewindow::shadewindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(800,600);
    this->setPalette(Qt::black);
    //设置窗口透明度
    this->setWindowOpacity(0.5);
    //去掉标题栏
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
}
