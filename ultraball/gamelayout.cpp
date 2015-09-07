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

    isMousePress = false;

    timer.setInterval(100 / 6);
    //connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(act()));
    timer.start();
}

GameLayout::~GameLayout()
{
    delete ui;
}

void GameLayout::paintEvent(QPaintEvent *event)
{
    paintItem();
    event->accept();
}

void GameLayout::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton) {
        isMousePress = true;
        mousePressPosition = event->pos();
        currentCursorPosition = event->pos();
    }

    event->accept();
}

void GameLayout::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (!isMousePress) {
            return;
        }
        isMousePress = false;
        if (mousePressPosition == event->pos()) {
            return;
        }
        CoreService::getInstance()->addWall(ItemType::commonWall, mousePressPosition, event->pos());
    }

    event->accept();
}

void GameLayout::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        if (!isMousePress) {
            return;
        }
        currentCursorPosition = event->pos();
    }

    event->accept();
}

void GameLayout::paintItem()
{
    QPainter painter(this);

    QPen pen = painter.pen();
    pen.setColor(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);

    if (isMousePress) {
        painter.drawLine(mousePressPosition, currentCursorPosition);
    }

    PaintService::paint(&painter);
}

void GameLayout::act()
{
    Item::setWindowHeight(this->size().height());
    Item::setWindowWidth(this->size().width());
    CoreService::getInstance()->act();
}
