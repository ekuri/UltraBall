#include "commonwall.h"

CommonWall::CommonWall(const QPointF &initialStartPosition, const QPointF &initialEndPosition) :
    AbstractWall(initialStartPosition, initialEndPosition)
{
    itemType = ItemType::commonWall;
}

list<Item *> CommonWall::getProcessItem()
{
    return list<Item *>();
}

void CommonWall::processItem(list<Item *> targetItems)
{

}

void CommonWall::changeStatus()
{

}

void CommonWall::handleAnimation()
{

}

