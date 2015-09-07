#ifndef GRAVITYBALL_H
#define GRAVITYBALL_H

#include "commonball.h"

class GravityBall : public CommonBall
{
public:
    GravityBall(const QPointF &initialPosition, const QPointF &initialVelocity, qreal initialRadius);
    list<Item *> getProcessItem();
    void processItem(list<Item *> targetItems);
};

#endif // GRAVITYBALL_H
