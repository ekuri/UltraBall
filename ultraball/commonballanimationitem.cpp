#include "commonballanimationitem.h"
#include "ultraballhelper.h"
#include "coreservice.h"

#include <math.h>

CommonBallAnimationItem::CommonBallAnimationItem(AbstractBall *initialTarget) :
   AbstractAnimationItem (initialTarget),
   moveDirection(drand48() * 2 - 1.0, drand48() * 2 - 1.0)
{
    itemType = ItemType::commonBallAnimationItem;
}

void CommonBallAnimationItem::act()
{
    position += moveDirection;
    if (UltraBallHelper::isOutOfBound(position)) {
       CoreService::getInstance()->removeAndDeleteAnimationItem(this);
    }
}
