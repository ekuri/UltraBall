#ifndef ABSTACTANIMATIONITEM_H
#define ABSTACTANIMATIONITEM_H

#include "abstractball.h"
#include <QPointF>

class AbstractAnimationItem : public Item
{
public:
    explicit AbstractAnimationItem(AbstractBall *initialTarget);
    virtual ~AbstractAnimationItem() {}
    virtual void act() = 0;

    QPointF getPosition() const;

    AbstractBall *getTarget() const;

protected:
    AbstractBall *target;
    QPointF position;
};

#endif // ABSTACTANIMATIONITEM_H
