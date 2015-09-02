#include "coreservice.h"
#include <stdlib.h>
#include <time.h>

#include "commonball.h"

CoreService* CoreService::instance = NULL;

CoreService::CoreService()
{
    srand(time(NULL));
}
list<AbstractWall *> &CoreService::getWallList()
{
    return wallList;
}


CoreService *CoreService::getInstance()
{
    return (instance != NULL)?instance:instance = new CoreService();
}

list<AbstractBall *> &CoreService::getBallList()
{
    return ballList;
}

void CoreService::act()
{
    foreach (AbstractBall *b, ballList) {
        b->act();
    }
}

bool CoreService::addItemRandomly(ItemType::type type)
{
    if (type == ItemType::commonBall) {
        ballList.push_back(new CommonBall(
                               QPointF(rand() % Item::getWindowWidth(), rand() % Item::getWindowHeight()),
                               QPointF(rand() % 5, rand() % 5), rand() % 10 + 20));
        return true;
    }

    return false;
}

bool CoreService::addItem(ItemType::type type)
{

    return false;
}


