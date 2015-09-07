#include "gravityball.h"
#include "coreservice.h"
#include "ultraballhelper.h"

#include <math.h>
#include <QDebug>

GravityBall::GravityBall(const QPointF &initialPosition, const QPointF &initialVelocity, qreal initialRadius)
    : CommonBall(initialPosition, initialVelocity, initialRadius)
{
    itemType = ItemType::gravityBall;
}

list<Item *> GravityBall::getProcessItem()
{
    list<Item *> resultList = CommonBall::getProcessItem();
    foreach (AbstractBall *b, CoreService::getInstance()->getBallList()) {
        if (b == this) {
            continue;
        }
        resultList.push_back(b);
    }

    return resultList;
}

void GravityBall::processItem(list<Item *> targetItems)
{
    CommonBall::processItem(targetItems);

    QPointF sumGravity(0, 0);
    qreal selfWeight = M_PI * radius * radius;
    qreal targetWeight = 0;
    qreal distanceToTarget = 0;
    qreal gravityFactor = 0.001;

    foreach (Item *item, targetItems) {
        if (item->getItemType() == ItemType::gravityBall) {

            AbstractBall *abstractBall = dynamic_cast <AbstractBall *> (item);
            targetWeight = M_PI * abstractBall->getRadius() * abstractBall->getRadius();
            distanceToTarget = UltraBallHelper::distanceBetween(position, abstractBall->getPosition());

            qDebug() << "distance: " << distanceToTarget;

            // calculate gravity
            sumGravity += selfWeight * targetWeight * gravityFactor / (distanceToTarget * distanceToTarget) * (abstractBall->getPosition() - position);

        }
    }

    qDebug() << "sum gravity: " << sumGravity;

    velocity = UltraBallHelper::getVelocityChangeByDirection(velocity, sumGravity, false);
}

