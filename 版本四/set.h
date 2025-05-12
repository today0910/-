#ifndef SET_H
#define SET_H

#include <QMainWindow>
#include"mypushbutton.h"


class set : public QMainWindow
{
    Q_OBJECT
public:
    explicit set(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);


signals:
    void setBack();
    void stopMusic();    // 信号：停止音乐
    void playMusic();    // 信号：播放音乐
private:
    MyPushButton *musicbtn;
    bool musicPlaying = true;  // 记录音乐状态
};

#endif // SET_H
