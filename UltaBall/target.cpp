#include "target.h"
#include "coreservice.h"

Target::Target(int size)
{
    geometry.setTopLeft(QPoint(CoreService::getInstance()->getWindowWidth() / 2,
                               CoreService::getInstance()->getWindowHeight() / 2));
    geometry.setSize(QSize(size, size));
    dx = random() % 3 - 1;
    dy = random() % 3 - 1;
}
QRect Target::getGeometry() const
{
    return geometry;
}

void Target::setGeometry(const QRect &value)
{
    geometry = value;
}

void Target::moveNext()
{
    geometry.translate(dx, dy);
    if (geometry.x() < 0) {
        dx = -dx;
        geometry.setX(0);
    }
    if (geometry.y() < 0) {
        dy = -dy;
        geometry.setY(0);
    }
    if (geometry.x() + geometry.height() > CoreService::getInstance()->getWindowWidth()) {
        dx = -dx;
        //geometry.setX();
        geometry.moveLeft(CoreService::getInstance()->getWindowWidth() - geometry.width());
    }
    if (geometry.y() + geometry.height() > CoreService::getInstance()->getWindowHeight()) {
        dy = -dy;
        geometry.moveTop(CoreService::getInstance()->getWindowHeight() - geometry.height() );
    }
}

