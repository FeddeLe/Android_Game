#ifndef PROJ_ANDROID_FISHBUBBLE_H
#define PROJ_ANDROID_FISHBUBBLE_H

#include "cocos2d.h"

#define FISH_BUBBLE_COLLISION_BITMASK 0x000003

class fishBubble
{
public:
    fishBubble();
    void fireFishBubble(cocos2d::Layer *layer, cocos2d::Vec2 touchLocation);

private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
};

#endif //PROJ_ANDROID_FISHBUBBLE_H
