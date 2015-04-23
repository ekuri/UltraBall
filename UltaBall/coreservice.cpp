#include "coreservice.h"

CoreService* CoreService::instance = NULL;

CoreService *CoreService::getInstance()
{
    if (instance == NULL)
        instance = new CoreService();
    return instance;
}

void CoreService::addBall(Ball b)
{
    ballList->push_back(b);
}

void CoreService::addWall(Wall w)
{
    wallList->push_back(w);
}

CoreService::CoreService()
{
    ballList = new list<Ball>();
    wallList = new list<Wall>();
}
list<Wall> *CoreService::getWallList() const
{
    return wallList;
}

void CoreService::setWallList(list<Wall> *value)
{
    wallList = value;
}

bool CoreService::removeBall(int id)
{
    for (list<Ball>::iterator it = ballList->begin(); it != ballList->end(); it++) {
        if (it->getId() == id) {
            ballList->erase(it);
            return true;
        }
    }
    return false;
}

bool CoreService::removeWall(int id)
{
    for (list<Wall>::iterator it = wallList->begin(); it != wallList->end(); it++) {
        if (it->getId() == id) {
            wallList->erase(it);
            return true;
        }
    }
    return false;
}

bool CoreService::ballsAction(double width, double height, const QRect &geometry)
{
    bool anyHit = false;
    for (list<Ball>::iterator it = ballList->begin(); it != ballList->end(); it++) {
        anyHit = anyHit || it->action(width, height, geometry);
    }
    return anyHit;
}

void CoreService::checkWallsAge()
{
    for (list<Wall>::iterator it = wallList->begin(); it != wallList->end(); it++) {
        it->setAge(it->getAge() + 10);
        if (it->getAge() > MAX_AGE) {
            it = wallList->erase(it);
        }
    }
}

list<Ball> *CoreService::getBallList() const
{
    return ballList;
}

void CoreService::setBallList(list<Ball> *value)
{
    ballList = value;
}

