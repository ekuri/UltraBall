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
    void paintItem();

private:
    Ui::GameLayout *ui;
    QTimer timer;
};

#endif // GAMELAYOUT_H
