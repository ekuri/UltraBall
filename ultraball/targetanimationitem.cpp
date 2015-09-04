#include "targetanimationitem.h"
#include <math.h>

TargetAnimationItem::TargetAnimationItem(AbstractBall *initialTarget, qreal initialAngle) :
    AbstractAnimationItem(initialTarget)
{
    angle = initialAngle;
    itemType = ItemType::targetAnimationItem;
}

void TargetAnimationItem::act()
{
    qreal followRadius = target->getRadius() * 2.0;
    QPointF targetPosition = target->getPosition();

    position = targetPosition + QPointF(cos(angle) * followRadius, sin(angle) * followRadius);

    angle = ((angle += 0.1) >  2.0 * M_PI)?(angle - 2.0 * M_PI):angle;
}

