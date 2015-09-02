#ifndef CORESERVICE_H
#define CORESERVICE_H

#include "abstractball.h"
#include "abstractwall.h"

class CoreService
{
public:
    static CoreService* getInstance();

    void act();
    bool addItemRandomly(ItemType::type type);
    bool addItem(ItemType::type type);

    static int getWindowHeight();
    static void setWindowHeight(int value);

    static int getWindowWidth();
    static void setWindowWidth(int value);

    list<AbstractBall *> &getBallList();
    list<AbstractWall *> &getWallList();

private:
    CoreService();
    static CoreService *instance;
    list<AbstractBall *> ballList;
    list<AbstractWall *> wallList;
};

#endif // CORESERVICE_H
