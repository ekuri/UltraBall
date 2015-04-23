#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include "ball.h"
#include <QTimer>
#include <QPaintEvent>
#include <QTime>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_addBtn_clicked();
    void checkWalls();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QTimer timer;
    QPoint startPoint, endPoint;
    bool mouseClicked;
};

#endif // MAINWINDOW_H
