#ifndef TARGETANIMATIONITEM_H
#define TARGETANIMATIONITEM_H

#include "abstractanimationitem.h"

class TargetAnimationItem : public AbstractAnimationItem
{
public:
    TargetAnimationItem(AbstractBall *initialTarget, qreal initialAngle);
    void act();

protected:
    qreal angle;
};

#endif // TARGETANIMATIONITEM_H
