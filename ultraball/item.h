#ifndef ITEM_H
#define ITEM_H

#include "itemtype.h"

class Item
{
public:
    Item();

    ItemType::type getItemType() const;

    static void setWindowHeight(int value);

    static void setWindowWidth(int value);

protected:
    ItemType::type itemType;
    static int windowHeight;
    static int windowWidth;
};

#endif // ITEM_H
