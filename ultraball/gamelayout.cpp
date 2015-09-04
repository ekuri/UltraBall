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
    if (count++ % 20 == 0) {
        CoreService::getInstance()->addItemRandomly(ItemType::commonBall);
    }
    CoreService::getInstance()->act();
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
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(3);
    painter.setPen(pen);

    if (isMousePress) {
        painter.drawLine(mousePressPosition, currentCursorPosition);
    }

    PaintService paintService(&painter);
    paintService.paint();

}
