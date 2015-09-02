#include "item.h"

int Item::windowHeight = 0;
int Item::windowWidth = 0;

Item::Item()
{
    itemType = ItemType::noType;
}
ItemType::type Item::getItemType() const
{
    return itemType;
}
void Item::setWindowHeight(int value)
{
    windowHeight = value;
}
void Item::setWindowWidth(int value)
{
    windowWidth = value;
}




