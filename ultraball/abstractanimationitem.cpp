#include "abstractanimationitem.h"

AbstractAnimationItem::AbstractAnimationItem(AbstractBall *initialTarget)
{
    itemType = ItemType::abstractAnimationItem;
    target = initialTarget;
    position = initialTarget->getPosition();
}
QPointF AbstractAnimationItem::getPosition() const
{
    return position;
}
AbstractBall *AbstractAnimationItem::getTarget() const
{
    return target;
}

