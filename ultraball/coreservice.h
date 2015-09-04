#ifndef CORESERVICE_H
#define CORESERVICE_H

#include "abstractball.h"
#include "abstractwall.h"
#include "abstractanimationitem.h"

class CoreService
{
public:
    static CoreService* getInstance();

    void act();
    bool addItemRandomly(ItemType::type type);
    bool addWall(ItemType::type type, const QPointF &initialStartPosition, const QPointF &initialEndPosition);

    static int getWindowHeight();
    static void setWindowHeight(int value);

    static int getWindowWidth();
    static void setWindowWidth(int value);

    list<AbstractBall *> &getBallList();
    list<AbstractWall *> &getWallList();
    list<AbstractAnimationItem *> &getAnimationItems();

private:
    CoreService();
    static CoreService *instance;
    list<AbstractBall *> ballList;
    list<AbstractWall *> wallList;
    list<AbstractAnimationItem *> animationItems;
};

#endif // CORESERVICE_H
