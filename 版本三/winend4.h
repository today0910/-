#ifndef WINEND4_H
#define WINEND4_H

#include <QMainWindow>

namespace Ui {
class winend4;
}

class winend4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit winend4(QWidget *parent = nullptr);
    ~winend4();
    void paintEvent(QPaintEvent*);

private:
    Ui::winend4 *ui;
signals:
    void CloseWinend4();
};

#endif // WINEND4_H
