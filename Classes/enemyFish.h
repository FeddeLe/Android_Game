#ifndef PROJ_ANDROID_ENEMYFISH_H
#define PROJ_ANDROID_ENEMYFISH_H

#include "cocos2d.h"

#define ENEMY_FISH_UPPER_SCREEN_THRESHOLD 0.80
#define ENEMY_FISH_LOWER_SCREEN_THRESHOLD 0.10
#define ENEMY_FISH_COLLIOSION_BITMASK 0x000002

class enemyFish
{
public:
    enemyFish();

    void spawnEnemyFish(cocos2d::Layer *layer);

private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
};

#endif //PROJ_ANDROID_ENEMYFISH_H
