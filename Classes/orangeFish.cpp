#include "orangeFish.h"

orangeFish::orangeFish(cocos2d::Layer *layer)
{
    visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    pOrangeFish = cocos2d::Sprite::create("fish.png");
    pOrangeFish->setScale(0.5);
    pOrangeFish->setPosition(cocos2d::Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    auto orangeFishBody = cocos2d::PhysicsBody::createCircle(pOrangeFish->getContentSize().width/2);
    orangeFishBody->setGravityEnable(false);
    orangeFishBody->setCollisionBitmask(FISH_COLLISION_BITMASK);
    orangeFishBody->setContactTestBitmask(true);
    pOrangeFish->setPhysicsBody(orangeFishBody);
    layer->addChild(pOrangeFish, 100);
}