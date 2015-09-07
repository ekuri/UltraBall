#ifndef COMMONBALLANIMATIONITEM_H
#define COMMONBALLANIMATIONITEM_H

#include "abstractanimationitem.h"

class CommonBallAnimationItem : public AbstractAnimationItem
{
public:
    explicit CommonBallAnimationItem(AbstractBall *initialTarget);
    virtual ~CommonBallAnimationItem() {}
    void act();

protected:
    QPointF moveDirection;
};

#endif // COMMONBALLANIMATIONITEM_H
