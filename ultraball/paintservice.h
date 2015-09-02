#ifndef PAINTSERVICE_H
#define PAINTSERVICE_H

#include <QPainter>

class PaintService
{
public:
    explicit PaintService(QPainter *initialPainter);
    void paint();

private:
    QPainter *painter;
};

#endif // PAINTSERVICE_H
