#include "commonballanimationitem.h"
#include "ultraballhelper.h"
#include "coreservice.h"

#include <math.h>

CommonBallAnimationItem::CommonBallAnimationItem(AbstractBall *initialTarget) :
   AbstractAnimationItem (initialTarget),
   moveDirection(-initialTarget->getVelocity() + QPointF(rand() % 3 - 1, rand() % 3 - 1))
{
    itemType = ItemType::commonBallAnimationItem;
}

void CommonBallAnimationItem::act()
{
    if (UltraBallHelper::isOutOfBound(position)) {
       CoreService::getInstance()->getAnimationItems().remove(this);
       delete this;
    }
}

