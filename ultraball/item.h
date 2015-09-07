#ifndef ITEM_H
#define ITEM_H

#include "itemtype.h"

class Item
{
public:
    Item();
    virtual ~Item() {}
    ItemType::type getItemType() const;

    static int getWindowHeight();
    static void setWindowHeight(int value);

    static int getWindowWidth();
    static void setWindowWidth(int value);

protected:
    ItemType::type itemType;
    static int windowHeight;
    static int windowWidth;
};

#endif // ITEM_H
