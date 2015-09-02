#ifndef GAMELAYOUT_H
#define GAMELAYOUT_H

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

private:
    Ui::GameLayout *ui;
};

#endif // GAMELAYOUT_H
