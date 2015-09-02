#ifndef PHYSICALITEM_H
#define PHYSICALITEM_H

#include "item.h"

#include <list>

using namespace::std;

class PhysicalItem : public Item
{
public:
    PhysicalItem();
    virtual list<Item*> getProcessItem() = 0;
    virtual void processItem(list<Item*> targetItems) = 0;
    virtual void act() = 0;
};

#endif // PHYSICALITEM_H
