#ifndef PROJ_ANDROID_ORANGEFISH_H
#define PROJ_ANDROID_ORANGEFISH_H

#include "cocos2d.h"

#define FISH_COLLISION_BITMASK 0x000001

class orangeFish
{
public:
    orangeFish(cocos2d::Layer *layer);
    cocos2d::Sprite *pOrangeFish;

private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
};

#endif //PROJ_ANDROID_ORANGEFISH_H
