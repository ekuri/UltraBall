#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QPaintEvent>
#include <QTime>
#include <QDebug>
#include "ball.h"
#include "mainlayout.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    MainLayout *mainLayout;

protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // MAINWINDOW_H
