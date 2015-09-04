#ifndef COMMONBALLANIMATIONITEM_H
#define COMMONBALLANIMATIONITEM_H

#include "abstractanimationitem.h"

class CommonBallAnimationItem : public AbstractAnimationItem
{
public:
    CommonBallAnimationItem(AbstractBall *initialTarget);
    void act();

protected:
    QPointF moveDirection;
};

#endif // COMMONBALLANIMATIONITEM_H
