#include "gameScene.h"

cocos2d::Scene* gameScene::createScene()
{
    auto scene = cocos2d::Scene::createWithPhysics();
    auto layer = gameScene::create();
    layer->setPhycsWrld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}

bool gameScene::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    auto backgroundImage = cocos2d::Sprite::create("background.png");
    backgroundImage->setPosition(cocos2d::Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    backgroundImage->setScale(visibleSize.width,visibleSize.height);
    this->addChild(backgroundImage);
    auto edgeBody = cocos2d::PhysicsBody::createEdgeBox(visibleSize, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(cocos2d::Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);
    auto StaticspawnEnemyFishs = static_cast<cocos2d::SEL_SCHEDULE>(&gameScene::spawnEnemyFishs);
    this->schedule(StaticspawnEnemyFishs, 0.0010*visibleSize.width);
    pOrangeFish = new orangeFish(this);
    auto contactListener = cocos2d::EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(gameScene::onContactBegin, this);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(gameScene::onTouchBegan, this);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(gameScene::onTouchMoved, this);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(gameScene::onTouchEnded, this);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    return true;
}

void gameScene::spawnEnemyFishs(float dt)
{
    oEnemyFish.spawnEnemyFish(this);
}

bool gameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{
    cocos2d::PhysicsBody *p = contact.getShapeA()->getBody();
    cocos2d::PhysicsBody *z = contact.getShapeB()->getBody();
    if((FISH_COLLISION_BITMASK == p->getCollisionBitmask() && ENEMY_FISH_COLLIOSION_BITMASK == z->getCollisionBitmask()) || (FISH_COLLISION_BITMASK == z->getCollisionBitmask() && ENEMY_FISH_COLLIOSION_BITMASK == p->getCollisionBitmask()))
    {
        auto scene = cocos2d::Scene::create();
        cocos2d::Director::getInstance()->replaceScene(TransitionFade::create(3, scene));
        cocos2d::Director::getInstance()->replaceScene(TransitionFade::create(5, HelloWorld::createScene()));
    }
    else if(FISH_BUBBLE_COLLISION_BITMASK == p->getCollisionBitmask() && ENEMY_FISH_COLLIOSION_BITMASK == z->getCollisionBitmask() || FISH_BUBBLE_COLLISION_BITMASK == z->getCollisionBitmask() && ENEMY_FISH_COLLIOSION_BITMASK == p->getCollisionBitmask())
    {
        this->removeChild(p->getNode(), true);
        this->removeChild(z->getNode(), true);
        this->removeChildByTag(123, true);
    }
    return true;
}

bool gameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    pOrangeFish->pOrangeFish->setTexture("fishBubble.png");
    cocos2d::Vec2 touchLocation = touch->getLocation();
    auto angle = atan2(touchLocation.y - pOrangeFish->pOrangeFish->getPosition().y, touchLocation.x - pOrangeFish->pOrangeFish->getPosition().x);
    pOrangeFish->pOrangeFish->setRotation(CC_RADIANS_TO_DEGREES(-angle) - 90);
    //float angleRotateBy = atan2(pOrangeFish->pOrangeFish->getPosition().y, pOrangeFish->pOrangeFish->getPosition().x) - atan2(touchLocation.y, touchLocation.x);
    //auto rotateAction = cocos2d::RotateBy::create(0.1, CC_RADIANS_TO_DEGREES(angleRotateBy));
    //pOrangeFish->pOrangeFish->runAction(rotateAction);
    oFishBubble.fireFishBubble(this, touchLocation);
    return true;
}

void gameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    pOrangeFish->pOrangeFish->setTexture("fish.png");
    cocos2d::Vec2 touchLocation = touch->getLocation();
    //float angleRotateBy = atan2(pOrangeFish->pOrangeFish->getPosition().y, pOrangeFish->pOrangeFish->getPosition().x) - atan2(touchLocation.y, touchLocation.x);
    auto angle = atan2(touchLocation.y - pOrangeFish->pOrangeFish->getPosition().y, touchLocation.x - pOrangeFish->pOrangeFish->getPosition().x);
    pOrangeFish->pOrangeFish->setRotation(CC_RADIANS_TO_DEGREES(-angle) - 90);
    //auto rotateAction = cocos2d::RotateBy::create(0.1, CC_RADIANS_TO_DEGREES(angleRotateBy));
    //pOrangeFish->pOrangeFish->runAction(rotateAction);
}

void gameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    pOrangeFish->pOrangeFish->setTexture("fish.png");
    cocos2d::Vec2 touchLocation = touch->getLocation();
    auto angle = atan2(touchLocation.y - pOrangeFish->pOrangeFish->getPosition().y, touchLocation.x - pOrangeFish->pOrangeFish->getPosition().x);
    pOrangeFish->pOrangeFish->setRotation(CC_RADIANS_TO_DEGREES(-angle) - 90);
}