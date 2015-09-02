#include "gamelayout.h"
#include "ui_gamelayout.h"

#include <QPainter>

#include "commonball.h"
#include "paintservice.h"
#include "coreservice.h"

GameLayout::GameLayout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameLayout)
{
    ui->setupUi(this);

    timer.setInterval(10);
    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start();
}

GameLayout::~GameLayout()
{
    delete ui;
}

void GameLayout::paintEvent(QPaintEvent *event)
{
    Item::setWindowHeight(this->size().height());
    Item::setWindowWidth(this->size().width());
    static int count = 0;
    if (count++ % 10 == 0) {
        CoreService::getInstance()->addItemRandomly(ItemType::commonBall);
    }
    CoreService::getInstance()->act();
    paintItem();
    event->accept();
}

void GameLayout::paintItem()
{
    QPainter p(this);
    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);

    PaintService ps(&p);
    ps.paint();
}
