#ifndef ABSTACTANIMATIONITEM_H
#define ABSTACTANIMATIONITEM_H

#include "abstractball.h"
#include <QPointF>

class AbstractAnimationItem : public Item
{
public:
    AbstractAnimationItem(AbstractBall *initialTarget);
    virtual void act() = 0;

    QPointF getPosition() const;

    AbstractBall *getTarget() const;

protected:
    AbstractBall *target;
    QPointF position;
};

#endif // ABSTACTANIMATIONITEM_H
