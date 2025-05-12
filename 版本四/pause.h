#ifndef PAUSE_H
#define PAUSE_H

#include <QMainWindow>
#define PAUSE_H


namespace Ui {
class Pause;
}

class Pause : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pause(QWidget *parent = nullptr);
    ~Pause();
    void paintEvent(QPaintEvent*);

private:
    Ui::Pause *ui;
signals:
    void menus();
    void continue_();
};

#endif // PAUSE_H
