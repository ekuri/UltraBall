#ifndef PAINTSERVICE_H
#define PAINTSERVICE_H

#include <QPainter>
#include "coreservice.h"

class PaintService
{
public:
    inline explicit PaintService(QPainter *initialPainter)
    {
        painter = initialPainter;
    }
    inline void paint() {
        CoreService *coreServiceInstance = CoreService::getInstance();
        foreach (AbstractBall *b, coreServiceInstance->getBallList()) {
            painter->drawEllipse(b->getPosition(), b->getRadius(), b->getRadius());
        }

        foreach (AbstractWall *w, coreServiceInstance->getWallList()) {
            painter->drawLine(w->getStartPosition(), w->getEndPosition());
        }
    }

private:
    QPainter *painter;
};

#endif // PAINTSERVICE_H
