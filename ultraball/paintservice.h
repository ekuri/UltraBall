#ifndef PAINTSERVICE_H
#define PAINTSERVICE_H

#include <QPainter>
#include "coreservice.h"

class PaintService
{
public:
    inline static void paint(QPainter *painter) {
        CoreService *coreServiceInstance = CoreService::getInstance();
        painter->setRenderHint(QPainter::HighQualityAntialiasing);

        QPen pen;
        QBrush brush;

        pen.setColor(Qt::blue);
        pen.setWidth(3);
        painter->setPen(pen);

        foreach (AbstractWall *w, coreServiceInstance->getWallList()) {
            painter->drawLine(w->getStartPosition(), w->getEndPosition());
        }

        brush.setColor(Qt::blue);
        brush.setStyle(Qt::SolidPattern);
        painter->setBrush(brush);

        pen.setWidth(0);
        painter->setPen(pen);

        foreach (AbstractBall *b, coreServiceInstance->getBallList()) {
            painter->drawEllipse(b->getPosition(), b->getRadius(), b->getRadius());
        }

        pen.setWidth(2);
        pen.setColor(Qt::darkGreen);
        painter->setPen(pen);
        foreach (AbstractAnimationItem *animation, coreServiceInstance->getAnimationItems()) {
            if (animation->getItemType() == ItemType::commonBallAnimationItem) {
                painter->drawPoint(animation->getPosition());
            }
        }

    }

private:
    PaintService()
    {
    }
};

#endif // PAINTSERVICE_H
