#ifndef ABSTRACTWALL_H
#define ABSTRACTWALL_H

#include <QPointF>
#include "physicalitem.h"

class AbstractWall : public PhysicalItem
{
public:
    AbstractWall(const QPointF &initialStartPosition, const QPointF &initialEndPosition);

    virtual void changeStatus() = 0;
    void act();

    QPointF getStartPosition() const;

    QPointF getEndPosition() const;

private:
    QPointF startPosition;
    QPointF endPosition;
};

#endif // ABSTRACTWALL_H
