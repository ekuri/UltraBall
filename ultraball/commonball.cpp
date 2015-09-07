#include "commonball.h"
#include "coreservice.h"
#include "commonwall.h"
#include "ultraballhelper.h"
#include "commonballanimationitem.h"

#include <QDebug>

CommonBall::CommonBall(const QPointF &initialPosition, const QPointF &initialVelocity, qreal initialRadius)
    : AbstractBall(initialPosition, initialVelocity, initialRadius)
{
    itemType = ItemType::commonBall;
    actCount = 0;
}

list<Item *> CommonBall::getProcessItem()
{
    list<Item *> resultList;

    foreach (AbstractWall *w, CoreService::getInstance()->getWallList()) {
        resultList.push_back(w);
    }
    return resultList;
}

void CommonBall::processItem(list<Item *> targetItems)
{
    foreach (Item *i, targetItems) {
        if (i->getItemType() == ItemType::commonWall) {
            CommonWall *w = static_cast<CommonWall *> (i);
            QPointF leffPosition = w->getStartPosition();
            QPointF rightPosition = w->getEndPosition();

            bool isCrashToWall = false;
            // 使用二分法检测是否发生碰撞，若最后两点距离小于1，则无碰撞
            while (UltraBallHelper::distanceBetween(leffPosition, rightPosition) >= 1.0) {
                qreal leftDistance = UltraBallHelper::distanceBetween(position, leffPosition);
                qreal rightDistance = UltraBallHelper::distanceBetween(position, rightPosition);

                if (leftDistance <= radius || rightDistance <= radius) {
                    isCrashToWall = true;
                }

                if (leftDistance > rightDistance) {
                    leffPosition = (leffPosition + rightPosition) / 2;
                } else {
                    rightPosition = (leffPosition + rightPosition) / 2;
                }
            }

            if (isCrashToWall) {
                this->crashToWallThenBounce((leffPosition + rightPosition) / 2);
            }
        }
    }
}

void CommonBall::moveNext()
{
    position.rx() += velocity.x();
    position.ry() += velocity.y();
    if (position.x() - radius < 0) {
        position.rx() = radius;
        velocity.rx() = -velocity.x();
    }
    if (position.x() + radius > windowWidth) {
        position.rx() = windowWidth - radius;
        velocity.rx() = -velocity.x();
    }
    if (position.y() - radius < 0) {
        position.ry() = radius;
        velocity.ry() = -velocity.y();
    }
    if (position.y() + radius > windowHeight) {
        position.ry() = windowHeight - radius;
        velocity.ry() = -velocity.y();
    }
}

void CommonBall::crashToWallThenBounce(const QPointF &crashPoint)
{
    // 获得速度变化的方向向量
    QPointF directionChangeVector = position - crashPoint;
    velocity = UltraBallHelper::getVelocityChangeByDirection(velocity, directionChangeVector);
}

void CommonBall::handleAnimation()
{
    //CoreService::getInstance()->getAnimationItems().push_back(new CommonBallAnimationItem(this));
}

