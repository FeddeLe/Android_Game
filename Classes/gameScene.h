#ifndef PROJ_ANDROID_GAMESCENE_H
#define PROJ_ANDROID_GAMESCENE_H

#include "cocos2d.h"
#include "enemyFish.h"
#include "orangeFish.h"
#include "HelloWorldScene.h"
#include "fishBubble.h"
USING_NS_CC;

class gameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(gameScene);
private:
    void setPhycsWrld(cocos2d::PhysicsWorld *wrld)
    {
        sceneWorld = wrld;
    };

    void spawnEnemyFishs(float dt);

    bool onContactBegin(cocos2d::PhysicsContact &contact);

    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);

    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);

    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

    cocos2d::PhysicsWorld *sceneWorld;

    enemyFish oEnemyFish;

    orangeFish *pOrangeFish;

    fishBubble oFishBubble;
};
#endif //PROJ_ANDROID_GAMESCENE_H
