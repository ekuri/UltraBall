#include "commonball.h"
#include <QDebug>

CommonBall::CommonBall(const QPointF &initialPosition, const QPointF &initialVelocity, qreal initialRadius)
    : AbstractBall(initialPosition, initialVelocity, initialRadius)
{
    itemType = ItemType::commonBall;
}

list<Item *> CommonBall::getProcessItem()
{
    return list<Item*>();
}

void CommonBall::processItem(list<Item *> targetItems)
{

}

void CommonBall::moveNext()
{
    position.rx() += velocity.x();
    position.ry() += velocity.y();
    if (position.x() - radius < 0) {
        position.rx() = radius;
        velocity.rx() = -velocity.x();
    }
    if (position.x() + radius > windowWidth) {
        position.rx() = windowWidth - radius;
        velocity.rx() = -velocity.x();
    }
    if (position.y() - radius < 0) {
        position.ry() = radius;
        velocity.ry() = -velocity.y();
    }
    if (position.y() + radius > windowHeight) {
        position.ry() = windowHeight - radius;
        velocity.ry() = -velocity.y();
    }
}

