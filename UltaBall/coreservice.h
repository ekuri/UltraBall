#ifndef CORESERVICE_H
#define CORESERVICE_H

#define MAX_AGE 5000

#include <list>
#include <QPoint>
#include "ball.h"
#include "wall.h"

using std::list;

class CoreService
{
public:
    static CoreService *getInstance();
    void addBall(Ball b);
    void addWall(Wall w);

    list<Ball> *getBallList() const;
    void setBallList(list<Ball> *value);

    list<Wall> *getWallList() const;
    void setWallList(list<Wall> *value);

    bool removeBall(int id);
    bool removeWall(int id);

    bool ballsAction(double width, double height, const QRect &geometry);
    void checkWallsAge();
private:
    CoreService();
    static CoreService *instance;
    list<Ball> *ballList;
    list<Wall> *wallList;
};

#endif // CORESERVICE_H
