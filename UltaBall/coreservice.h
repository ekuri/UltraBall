#ifndef CORESERVICE_H
#define CORESERVICE_H

#define MAX_AGE 5000

#include <list>
#include <QPoint>
#include <QRect>
#include "ball.h"
#include "wall.h"
#include "action.h"
#include "target.h"

using std::list;

class CoreService
{
public:
    ~CoreService();
    static CoreService *getInstance();
    void addBall(Ball b);
    void addWall(Wall w);

    list<Ball> *getBallList() const;
    void setBallList(list<Ball> *value);

    list<Wall> *getWallList() const;
    void setWallList(list<Wall> *value);

    bool removeBall(int id);
    bool removeWall(int id);
    void resetAllElement();

    bool ballsAction();
    void checkWallsAge();
    void targetAction();

    int getWindowHeight() const;
    void setWindowHeight(int value);

    int getWindowWidth() const;
    void setWindowWidth(int value);

    QRect getTargetGeometry() const;
    void setTargetGeometry(const QRect &value);

    Action *getAction() const;
    void setActionAndDeleteOld(Action *value);

    Target *getTarget() const;
    void setTarget(Target *value);
    void removeTarget();

    int getScore() const;
    void setScore(int value);
    void scoreAdd(int increase);
    void scoreSub(int decrease);

    list<Ball> *getVirtualBallList() const;
    void setVirtualBallList(list<Ball> *value);
    void addVirtualBallInTarget();

private:
    CoreService();
    static CoreService *instance;
    list<Ball> *ballList;
    list<Wall> *wallList;
    list<Ball> *virtualBallList;
    int windowHeight;
    int windowWidth;
    Target *target;
    Action *action;
    int score;
    int frameCount;
};

#endif // CORESERVICE_H
