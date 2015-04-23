#ifndef BALL_H
#define BALL_H

#include <QPointF>
#include <QLine>
#include <math.h>
#include <QRect>
#include <QDebug>
#include <wall.h>

class Ball
{
public:
    Ball(double size);
    ~Ball();

    inline bool action(double height,double width, QRect target) {
        moveNext();
        bounce(height, width);
        bounceToLines();
        return hitTarget(target);
    }

    inline void moveNext() {
        posx += dx;
        posy += dy;
    }
    inline bool bounce(double height,double width) {
        if (posx < 0) {
            dx = -dx;
            posx = 0;
            return true;
        }
        if (posx + size > height) {
            dx = -dx;
            posx = height - size;
            return true;
        }
        if (posy < 0) {
            dy = -dy;
            posy = 0;
            return true;
        }
        if (posy + size > width) {
            dy = -dy;
            posy = width - size;
            return true;
        }
        return false;
    }

    inline QPointF getPos() {
        return QPointF(posx, posy);
    }
    inline double getSize() {
        return size;
    }

    bool testCrash(QPointF startPoint, QPointF endPoint);
    bool bounceToLine(QPointF startPoint, QPointF endPoint);
    void bounceToLines();
    bool hitTarget(QRect target);

    int getId() const;
    void setId(int value);

private:
    double posx, posy;
    double dx, dy;
    double size;
    int id;
    static int idCount;
};

#endif // BALL_H
