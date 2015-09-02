#include "abstractwall.h"

AbstractWall::AbstractWall(const QPointF &initialStartPosition, const QPointF &initialEndPosition)
{
    itemType = ItemType::abstractWall;
    startPosition = initialStartPosition;
    endPosition = initialEndPosition;
}

void AbstractWall::act()
{
    processItem(getProcessItem());
    changeStatus();
}

