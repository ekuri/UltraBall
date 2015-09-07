#ifndef ULTRABALLHELPER_H
#define ULTRABALLHELPER_H

#include <QPointF>
#include <math.h>
#include "item.h"

class UltraBallHelper
{
public:
    inline static qreal distanceBetween(const QPointF &firstPosition, const QPointF &secondPosition) {
        return sqrt(pow(firstPosition.x() - secondPosition.x(), 2) + pow(firstPosition.y() - secondPosition.y(), 2));
    }

    inline static QPointF getVelocityChangeByDirection(const QPointF &previousVelocity, const QPointF &direction, bool isHoldPreviousVelocityLength = true) {
        if (direction.y() == 0) {
            return QPointF(previousVelocity.x(), -previousVelocity.y());
        }
        if (direction.x() == 0) {
            return QPointF(-previousVelocity.x(), previousVelocity.y());
        }

        qreal previousVelocityLength = distanceBetween(QPointF(0, 0), previousVelocity);
        if (previousVelocityLength == 0) {
            return previousVelocity;
        }

        qreal directionLength = distanceBetween(QPointF(0, 0), direction);
        //QPointF unitDirection = direction / directionLength;
        //directionLength = distanceBetween(QPointF(0, 0), unitDirection);

        //qreal fabCosineValue = fabs(QPointF::dotProduct(unitDirection, previousVelocity) / fabs(directionLength * previousVelocityLength));
        qreal fabCosineValue = fabs(QPointF::dotProduct(direction, previousVelocity) / fabs(directionLength * previousVelocityLength));
        qreal changeVelocityLength = 2.0 * fabCosineValue * previousVelocityLength;

        //QPointF resultVelocity = previousVelocity + unitDirection * changeVelocityLength / directionLength;
        QPointF resultVelocity = previousVelocity + direction * changeVelocityLength / directionLength;
        if (isHoldPreviousVelocityLength) {
            qreal resultVelocityLength = UltraBallHelper::distanceBetween(QPointF(0, 0), resultVelocity);
            qreal resultPrecision = previousVelocityLength / resultVelocityLength;
            resultVelocity *= resultPrecision;
        }

        return resultVelocity;
    }

    inline static bool isOutOfBound(QPointF position) {
        return (position.x() < 0) || (position.x() > Item::getWindowWidth()) || (position.y() < 0) || (position.y() > Item::getWindowHeight());
    }

private:
    UltraBallHelper();
};

#endif // ULTRABALLHELPER_H
