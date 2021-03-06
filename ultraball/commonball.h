#ifndef COMMONBALL_H
#define COMMONBALL_H

#include "abstractball.h"
#include "abstractwall.h"

#include <QPainter>

class CommonBall : public AbstractBall
{
public:
    CommonBall(const QPointF &initialPosition, const QPointF &initialVelocity, qreal initialRadius);
    list<Item*> getProcessItem();
    void processItem(list<Item*> targetItems);
    void moveNext();
    void crashToWallThenBounce(const QPointF &crashPoint);
    void handleAnimation();

protected:
    int actCount;
};

#endif // COMMONBALL_H
