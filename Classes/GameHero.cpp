#include "GameHero.h"
#include "GameHeroBullet.h"
void GameHero::onEnter(){
	CCNode::onEnter();
	this->setContentSize(CCSizeMake(85, 90));
	initBulletAmount();
	initLife();
	level = 2;
	auto body = PhysicsBody::createCircle(20);
	body->setContactTestBitmask(0xFFFFFF);
	hero = CCSprite::create("plane.png");
	hero->setPhysicsBody(body);
	setType((level - 1) * 4 + 1, hero);
	hero->setPosition(Point(200, 30));
	currentPos = Point(200, 30);
	hero->setTag(1);
	beShooted();
	addChild(hero, 2);
	schedule(schedule_selector(GameHero::update), 0.01f, kRepeatForever, 0);
	schedule(schedule_selector(GameHero::update2), 0.05f, kRepeatForever, 0);
	auto listener = EventListenerKeyboard::create();
	listener->setEnabled(true);
	listener->onKeyPressed = CC_CALLBACK_2(GameHero::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameHero::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, hero);
}
//当按键时改变hero的运动状态(1->up,2->down,3->left,4->right)
void GameHero::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event){
	switch (keyCode){
	case EventKeyboard::KeyCode::KEY_Z:
		isShoot = true;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW :
		heroDir[1] = true;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		heroDir[2] = true;
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		heroDir[3] = true;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		heroDir[4] = true;
		break;
	}
}
void GameHero::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event){
	switch (keycode){
	case EventKeyboard::KeyCode::KEY_Z:
		isShoot = false;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		heroDir[1] = false;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		heroDir[2] = false;
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		heroDir[3] = false;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		heroDir[4] = false;
		break;
	}
}
void GameHero::update(float dt){
	auto pos = hero->getPosition();
	if (heroDir[1] == true){
		pos.y = pos.y + 3;
		setType((level - 1) * 4 + 1, hero);
	}
	if (heroDir[2] == true){
		pos.y = pos.y - 3;
	}
	if (heroDir[3] == true){
		pos.x = pos.x - 3;
		setType((level - 1) * 4 + 2, hero);
	}
	if (heroDir[4] == true){
		pos.x = pos.x + 3;
		setType((level - 1) * 4 + 3, hero);
	}
	if (heroDir[3] == false && heroDir[4] == false){
		setType((level - 1) * 4 + 1, hero);
	}
	if (heroDir[3] == false && heroDir[4] == false && isShoot == true){
		setType((level - 1) * 4 + 4, hero);
	}
	hero->setPosition(Point(pos.x, pos.y));
	currentPos = pos;
}
CCNode* GameHero::getCurrentPosition(){
	return hero;
}
void GameHero::update2(float dt){
	if (isShoot == true){
		releaseBullet();
	}
}
void GameHero::releaseBullet(){
	int bp;
	int a = bulletAmount;
	for (int i = 0; i < bulletAmount; i++){
		if (bulletAmount == 2){
			if (i == 0)
				bp = -1;
			else
				bp = 1;
		}
		else if (bulletAmount == 3){
			if (i == 0)
				bp = 0;
			else if (i == 1)
				bp = -2;
			else
				bp = 2;
		}
		else
			bp = 0;
		auto myheroBullet = GameHeroBullet::create();
		myheroBullet->setType(29);
		Size winSize = Director::getInstance()->getWinSize();
		auto planePos = hero->getPosition();
		Point bulletPos = (Point(planePos.x+bp*10, planePos.y + hero->getContentSize().height / 2 + 20));
		myheroBullet->setPosition(bulletPos);
		float flyLength = winSize.height - planePos.y;
		float flyDuration = flyLength / myheroBullet->getFlySpeed();
		CCActionInterval* actionMove = MoveTo::create(flyDuration, Point(planePos.x+bp*10, winSize.height - 10));
		auto actionDone = CallFuncN::create(CC_CALLBACK_1(GameHeroBullet::removeBullet, myheroBullet));
		Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
		myheroBullet->runAction(sequence);
		addChild(myheroBullet, 3);
	}
}
void GameHero::addBulletAmount(){
	bulletAmount++;
}
void GameHero::initBulletAmount(){
	bulletAmount = 3;
}
void GameHero::initLife(){
	life = 5;
}
void GameHero::addLife(){
	if (life<5)
	life++;
}
void GameHero::minusLife(){
	if (life > 0)
		life--;
}
void GameHero::beShooted(){
	auto blinkAction = CCBlink::create(1, 5);     //需要解决两个子弹同时撞到自己的情况
	minusLife();
	hero->runAction(blinkAction);
}
void GameHero::setType(int flag,CCSprite* pSprite){
	CCSprite * target;
	CCTexture2D* targetTexture;
	switch (flag){
	case 1:
		 target = CCSprite::create("plane.png");
		break;
	case 2 :
		 target = CCSprite::create("planeleft.png");
		break;
	case 3 :
		target = CCSprite::create("planeright.png");
		break;
	case 4:
		target = CCSprite::create("PlaneFight.png");
		break;
	case 5:
		target = CCSprite::create("GBA.png");
		break;
	case 6:
		target = CCSprite::create("GBA.png");
		break;
	case 7:
		target = CCSprite::create("GBA.png");
		break;
	case 8:
		target = CCSprite::create("GBAFight.png");
		break;
	case 9:
		target = CCSprite::create("planeleft.png");
		break;
	case 10:
		target = CCSprite::create("planeleft.png");
		break;
	case 11:
		target = CCSprite::create("planeleft.png");
		break;
	case 12:
		target = CCSprite::create("planeleft.png");
		break;
	case 13:
		target = CCSprite::create("planeleft.png");
		break;
	case 14:
		target = CCSprite::create("planeleft.png");
		break;
	case 15:
		target = CCSprite::create("planeleft.png");
		break;
	case 16:
		target = CCSprite::create("planeleft.png");
		break;

	}
	targetTexture = target->getTexture();
	pSprite->setTexture(targetTexture);
}
void GameHero::onExit(){
	CCNode::onExit();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}