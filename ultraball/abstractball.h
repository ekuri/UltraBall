#ifndef ABSTRACTBALL_H
#define ABSTRACTBALL_H

#include "physicalitem.h"
#include <QPointF>


class AbstractBall : public PhysicalItem
{
public:
    AbstractBall(const QPointF &initialPosition, const QPointF &initialVelocity, qreal initialRadius);

    virtual void moveNext() = 0;
    void act();

    qreal getRadius() const;

    QPointF getPosition() const;

    QPointF getVelocity() const;

protected:
    QPointF position;
    QPointF velocity;
    qreal radius;
};

#endif // ABSTRACTBALL_H
