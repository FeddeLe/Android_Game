#include "enemyFish.h"

USING_NS_CC;

enemyFish::enemyFish()
{
    visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    origin = cocos2d::Director::getInstance()->getVisibleOrigin();
}

void enemyFish::spawnEnemyFish(cocos2d::Layer *layer)
{
    auto enemyFishSprite = cocos2d::Sprite::create("badFish.png");
    enemyFishSprite->setScale(0.3);
    auto enemyFishBody = cocos2d::PhysicsBody::createBox(enemyFishSprite->getContentSize());
    enemyFishBody->setCollisionBitmask(ENEMY_FISH_COLLIOSION_BITMASK);
    enemyFishBody->setContactTestBitmask(true);

    auto random = CCRANDOM_0_1();

    if(random < ENEMY_FISH_LOWER_SCREEN_THRESHOLD)
    {
        random = ENEMY_FISH_LOWER_SCREEN_THRESHOLD;
    }
    else if(random > ENEMY_FISH_UPPER_SCREEN_THRESHOLD)
    {
        random = ENEMY_FISH_UPPER_SCREEN_THRESHOLD;
    }
    enemyFishBody->setDynamic(false);
    auto enemyFishPosition = 0;
    auto enemyFishWidthGap = CCRANDOM_MINUS1_1()*240;
    if(enemyFishWidthGap > 200 || enemyFishWidthGap < (-210))
    {
        enemyFishPosition = (random * visibleSize.height + enemyFishSprite->getContentSize().height);
        if(enemyFishWidthGap > 200)
        {
            enemyFishSprite->setRotation(45);
        }
        else
        {
            enemyFishSprite->setRotation(-45);
        }
    }
    else if(random >= 0.5)
    {
        enemyFishPosition = (random * visibleSize.height/4 + enemyFishSprite->getContentSize().height*2.5);
    }
    else if(random < 0.5)
    {
        enemyFishPosition = (random * visibleSize.height/4 + enemyFishSprite->getContentSize().height/4);
        enemyFishSprite->setRotation(180);
    }
    enemyFishSprite->setPhysicsBody(enemyFishBody);
    enemyFishSprite->setPosition(Point(visibleSize.width/3 + enemyFishSprite->getContentSize().width + origin.x + enemyFishWidthGap, enemyFishPosition));
    layer->addChild(enemyFishSprite);
    auto enemyFishAction = MoveTo::create(4, Point(visibleSize.width/2, visibleSize.height/2));
    enemyFishSprite->runAction(enemyFishAction);
}