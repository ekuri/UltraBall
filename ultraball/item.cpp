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
int Item::getWindowHeight()
{
    return windowHeight;
}

void Item::setWindowHeight(int value)
{
    windowHeight = value;
}

int Item::getWindowWidth()
{
    return windowWidth;
}

void Item::setWindowWidth(int value)
{
    windowWidth = value;
}
