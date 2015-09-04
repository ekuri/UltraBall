#ifndef ITEMTYPE
#define ITEMTYPE

class ItemType {
public:
    enum type {
        noType,
        animationItem,
        physicalItem,
        abstractBall,
        commonBall,
        abstractWall,
        commonWall,
        abstractAnimationItem,
        commonBallAnimationItem,
        targetAnimationItem,
    };
};

#endif // ITEMTYPE

