#ifndef COMMONWALL_H
#define COMMONWALL_H

#include "abstractwall.h"

class CommonWall : public AbstractWall
{
public:
    CommonWall(const QPointF &initialStartPosition, const QPointF &initialEndPosition);
    list<Item*> getProcessItem();
    void processItem(list<Item*> targetItems);
    void changeStatus();
    void handleAnimation();
};

#endif // COMMONWALL_H
