#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameHero.h"
#include "GameEnemy.h"
#include "GameAllEnemy.h"
#include "GameEnemyBullet.h"
#include "GameHeroBullet.h"
#include "GameBonus.h"

using namespace cocostudio::timeline;
GameAllEnemy* myEnemy;
GameHero* myHero;
static int left = 1;
static int level = 1;
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0.0, 0.0));

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();
	//±³¾°
	auto bg1 = CCSprite::create("HelloWorld.png");
	bg1->setAnchorPoint(ccp(0, 0));
	bg1->setPosition(ccp(0, 0));
	addChild(bg1,0);
	//hero
	myHero = GameHero::create();
	addChild(myHero, 2);
	//schedule(schedule_selector(HelloWorld::update), 0.1f, kRepeatForever, 0);
	//enemy
	//auto theEnemy = GameEnemy::create();
	//addChild(theEnemy, 2);
	auto myScene = myHero->getParent();
	myEnemy = GameAllEnemy::create();
	myEnemy->setScene(myScene);
	schedule(schedule_selector(HelloWorld::update), 0.1f, kRepeatForever, 0);
	myEnemy->enemyAppear();
	addChild(myEnemy, 5);

	
	
	/*auto enemyBullet = GameEnemyBullet::create();
	addChild(enemyBullet, 3);*/
    return true;
}
void HelloWorld::update(float dt){
	if (myHero != NULL){
		auto hero = myHero->getCurrentPosition();
		myEnemy->getShootTarget(hero);
	}
	srand((unsigned)time(0)*left);
	left = rand() % (int)(800);
	if (left%40 == level*2+1||left%40==level*2){
		auto body = PhysicsBody::createCircle(20);
		body->setContactTestBitmask(0xFFFFFF);
		auto bonus = GameBonus::create();
		bonus->setPhysicsBody(body);
		bonus->setPosition(Point(left, 1000));
		if (left%40 == level*2)
			bonus->setBonusType(2);
		if (left % 40 == level * 2 + 1)
			bonus->setBonusType(3);
		auto flySpeed = bonus->getFlySpeed();
		auto flyDuration = 10.0f;
		auto move1 = MoveTo::create(flyDuration, Point(left, -10));
		auto actionDone = CallFuncN::create(CC_CALLBACK_1(GameBonus::disappear, bonus));
		auto sequence = Sequence::create(move1, actionDone, NULL);
		bonus->runAction(sequence);
		addChild(bonus, 3);
	}
}
void HelloWorld::onEnter() {
	Layer::onEnter();
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [](PhysicsContact &contact) {
		CCSprite* spriteA = (CCSprite*)contact.getShapeA()->getBody()->getNode();
		CCSprite* spriteB = (CCSprite*)contact.getShapeB()->getBody()->getNode();
		if (spriteA != NULL && spriteB != NULL) {
			auto tagA = spriteA->getTag();
			auto tagB = spriteB->getTag();
			switch (tagA) {
			case 1:
				if (tagB >= 2 && tagB <= 5){
					myHero->addBulletAmount();
					auto node = (GameBonus *)spriteB;
					node->getPhysicsBody()->removeFromWorld();
					node->disappear(node);
				}
				else if (tagB >= 26 && tagB <= 29){
					myHero->beShooted();
					auto node = (GameHeroBullet *)spriteB;
					node->getPhysicsBody()->removeFromWorld();
					node->removeBullet(node);
					break;
				}
				break;
			case 2: case 3: case 4:case 5:
				if (tagB == 1) {
					myHero->addBulletAmount();
					auto node = (GameBonus *)spriteA;
					node->getPhysicsBody()->removeFromWorld();
					node->disappear(node);
				}
				break;
			case 6: case 7: case 8:case 9:
				if (tagB == 1) {
					myHero->addLife();
					auto node = (GameBonus *)spriteA;
					node->getPhysicsBody()->removeFromWorld();
					node->disappear(node);
				}
				break;
			case 10: case 11: case 12:case 13:
				if (tagB >= 26 && tagB <= 29) {
					//auto node = (GameEnemy *)spriteA;
					auto node = spriteA -> getParent();
					node->getPhysicsBody()->removeFromWorld();
					//node->dead(node);
				}
				else if (tagB == 1){
					/*auto node = (GameHero *)spriteB;
					node->getPhysicsBody()->removeFromWorld();
					node->dead(node);*/
				}
				break;
			case 14: case 15: case 16:case 17:case 18: case 19: case 20:case 21:case 22: case 23: case 24:case 25:
				if (tagB >= 26 && tagB <= 29) {
					//auto node = (GameEnemy *)spriteA;
					auto node = spriteA->getParent();
					node->getPhysicsBody()->removeFromWorld();
					//node->dead(node);
					
				}
				else if (tagB == 1) {

				}
				break;
			case 26: case 27: case 28:case 29:
				if (tagB >= 14 && tagB <= 25) {
					//auto node = (GameEnemy *)spriteB;
					auto node = spriteB->getParent();
					node->getPhysicsBody()->removeFromWorld();
					//node->dead(node);
				}
				else if (tagB >= 10 && tagB <= 13) {
					//auto node = (GameEnemy *)spriteB;
					auto node = spriteB->getParent();
					node->getPhysicsBody()->removeFromWorld();
					//node->dead(node);
				}
				else if (tagB == 1){
					myHero->beShooted();
					auto node = (GameHeroBullet *)spriteA;
					node->getPhysicsBody()->removeFromWorld();
					node->removeBullet(node);
				}
				break;
			default:
				if (tagB == 1) {

				}
				break;
			}
		}
		return true;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
}

void HelloWorld::onExit() {
	Layer::onExit();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}
