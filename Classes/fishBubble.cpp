#include "fishBubble.h"

fishBubble::fishBubble()
{
    visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    origin = cocos2d::Director::getInstance()->getVisibleOrigin();
}

void fishBubble::fireFishBubble(cocos2d::Layer *layer, cocos2d::Vec2 touchLocation)
{
    auto fishBubbleSprite = cocos2d::Sprite::create("bubble.png");
    fishBubbleSprite->setScale(0.5);
    fishBubbleSprite->setPosition(cocos2d::Point(visibleSize.width/2, visibleSize.height/2));
    auto fishBubbleBody = cocos2d::PhysicsBody::createBox(fishBubbleSprite->getContentSize());
    fishBubbleBody->setCollisionBitmask(FISH_BUBBLE_COLLISION_BITMASK);
    fishBubbleBody->setContactTestBitmask(true);
    fishBubbleBody->setGravityEnable(false);
    fishBubbleSprite->setPhysicsBody(fishBubbleBody);
    layer->addChild(fishBubbleSprite);
    auto fishBubbleAction = cocos2d::MoveTo::create(0.3, cocos2d::Point(touchLocation.x, touchLocation.y));
    fishBubbleSprite->runAction(fishBubbleAction);
    fishBubbleSprite->setTag(123);
}

