#ifndef WINEND3_H
#define WINEND3_H

#include <QMainWindow>

namespace Ui {
class winend3;
}

class winend3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit winend3(QWidget *parent = nullptr);
    ~winend3();
    void paintEvent(QPaintEvent*);

private:
    Ui::winend3 *ui;
signals:
    void CloseWinend3();
};

#endif // WINEND3_H
