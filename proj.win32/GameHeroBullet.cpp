#include "GameHeroBullet.h"
void GameHeroBullet::onEnter(){
	CCNode::onEnter();
	this->setContentSize(CCSizeMake(21, 52));
	addChild(heroBullet, 2);
}
void GameHeroBullet::removeBullet(Node *pNode){
	removeFromParentAndCleanup(pNode);
}
void GameHeroBullet::setType(int flag){
	auto body = PhysicsBody::createCircle(0.1);
	body->setContactTestBitmask(0xFFFFFF);
	switch (flag){
	case 26:
		heroBullet = CCSprite::create("bullet21.png");
		break;
	case 27:
		heroBullet = CCSprite::create("bullet22.png");
		break;
	case 28:
		heroBullet = CCSprite::create("bullet23.png");
		break;
	case 29:
		heroBullet = CCSprite::create("WIFI.png");
		break;
	case 30:
		heroBullet = CCSprite::create("bullet21.png");
		break;
	case 31:
		heroBullet = CCSprite::create("bullet22.png");
		break;
	case 32:
		heroBullet = CCSprite::create("bullet23.png");
		break;
	case 33:
		break;
	case 34:
		break;
	case 35:
		break;
	case 36:
		break;
	case 37:
		break;
	case 38:
		break;
	case 39:
		break;
	case 40:
		break;
	case 41:
		break;
	}
	heroBullet->setPhysicsBody(body);
	heroBullet->setTag(flag);
}
int GameHeroBullet::getFlySpeed(){
	return flySpeed;
}
