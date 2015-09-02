#include "paintservice.h"
#include "coreservice.h"

PaintService::PaintService(QPainter *initialPainter)
{
    painter = initialPainter;
}

void PaintService::paint()
{
    CoreService *coreServiceInstance = CoreService::getInstance();
    foreach (AbstractBall *b, coreServiceInstance->getBallList()) {
        painter->drawEllipse(b->getPosition(), b->getRadius(), b->getRadius());
    }

    foreach (AbstractWall *w, coreServiceInstance->getWallList()) {
        painter->drawLine(w->getStartPosition(), w->getEndPosition());
    }
}
