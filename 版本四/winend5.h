#ifndef WINEND5_H
#define WINEND5_H

#include <QMainWindow>

namespace Ui {
class winend5;
}

class winend5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit winend5(QWidget *parent = nullptr);
    ~winend5();
    void paintEvent(QPaintEvent*);

private:
    Ui::winend5 *ui;
signals:
    void CloseWinend5();
};

#endif // WINEND5_H
