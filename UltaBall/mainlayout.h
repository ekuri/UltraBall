#ifndef MAINLAYOUT_H
#define MAINLAYOUT_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QPaintEvent>
#include <QTime>
#include <QDebug>
#include "ball.h"

namespace Ui {
class MainLayout;
}

class MainLayout : public QWidget
{
    Q_OBJECT

public:
    explicit MainLayout(QWidget *parent = 0);
    ~MainLayout();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_addBallBtn_clicked();
    void checkWalls();

    void on_addTargetBtn_clicked();

    void on_resetBtn_clicked();

    void on_startBtn_clicked();

private:
    Ui::MainLayout *ui;
    QPixmap image;
    QTimer timer;
    QPoint startPoint, endPoint;
    bool mouseClicked;
    bool started;
};

#endif // MAINLAYOUT_H
