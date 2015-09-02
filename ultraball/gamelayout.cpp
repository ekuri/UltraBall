#include "gamelayout.h"
#include "ui_gamelayout.h"
#include <QPainter>


GameLayout::GameLayout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameLayout), b(QPointF(200, 100), QPointF(1, 1), 50.0)
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
    b.act();
    QPainter p(this);
    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);
    p.drawEllipse(b.getPosition(), b.getRadius(), b.getRadius());
    event->accept();
}
