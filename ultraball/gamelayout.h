#ifndef GAMELAYOUT_H
#define GAMELAYOUT_H

#include <QPaintEvent>
#include <QTimer>
#include <QWidget>

namespace Ui {
class GameLayout;
}

class GameLayout : public QWidget
{
    Q_OBJECT

public:
    explicit GameLayout(QWidget *parent = 0);
    ~GameLayout();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::GameLayout *ui;
    QTimer timer;

    bool isMousePress;
    QPointF mousePressPosition;
    QPointF currentCursorPosition;

    void paintItem();
};

#endif // GAMELAYOUT_H
