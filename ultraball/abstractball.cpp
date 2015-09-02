#include "abstractball.h"

AbstractBall::AbstractBall(const QPointF &initialPosition, const QPointF &initialVelocity, qreal initialRadius)
{
    itemType = ItemType::abstractBall;
    position = initialPosition;
    velocity = initialVelocity;
    radius = initialRadius;
}

void AbstractBall::act()
{
    processItem(getProcessItem());
    moveNext();
}
qreal AbstractBall::getRadius() const
{
    return radius;
}
QPointF AbstractBall::getPosition() const
{
    return position;
}
QPointF AbstractBall::getVelocity() const
{
    return velocity;
}




