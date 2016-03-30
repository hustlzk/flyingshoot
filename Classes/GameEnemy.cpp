#include "GameEnemy.h"
#include "GameEnemyBullet.h"
#include "GameBonus.h"
#include <stdlib.h>
void GameEnemy::onEnter(){
	CCNode::onEnter();
	this->setContentSize(CCSizeMake(85, 90));
}
void GameEnemy::setEnemyType(int flag){
	auto body = PhysicsBody::createCircle(20);
	body->setContactTestBitmask(0xFFFFFF);
	switch (flag){
	case 10:
		enemy = CCSprite::create("bee.png");
		break;
	case 11:
		enemy = CCSprite::create("turtle.png");
		break;
	case 12:
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	case 16:
		break;
	case 17:
		break;
	case 18:
		break;
	case 19:
		break;
	case 20:
		break;
	case 21:
		break;
	case 22:
		break;
	case 23:
		break;
	case 24:
		break;
	case 25:
		break;
	}
	enemy->setPhysicsBody(body);
	addChild(enemy);
	enemy->setTag(flag);
}
void GameEnemy::releaseBullet(int flag){
	auto enemyPos = this->getPosition();
	auto targetPoint = shootTarget->getPosition();
	auto enemyBullet = GameEnemyBullet::create();
	enemyBullet->setEnemyBulletType(flag, enemyPos,targetPoint);
	scene->addChild(enemyBullet, 3);
}
void GameEnemy::dead(Node *pNode){
	auto bonus = GameBonus::create();
	if (pNode->getTag() == 10){
		bonus->setBonusType(2);
	}
	if (pNode->getTag() == 11){
		bonus->setBonusType(3);
	}
	auto bonusPos = bonus->getPosition();
	bonus->setPosition(Point(bonusPos.x, bonusPos.y));
	auto flySpeed = bonus->getFlySpeed();
	auto flyDuration = bonusPos.y / flySpeed;
	auto move1 = MoveTo::create(flyDuration, Point(bonusPos.x, -10));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(GameBonus::disappear, bonus));
	auto sequence = Sequence::create(move1, actionDone, NULL);
	bonus->runAction(sequence);
	bonus->appearBonus();
	removeFromParentAndCleanup(pNode);
}
void GameEnemy::setScene(CCNode*p){
	scene = p;
}
void GameEnemy::setShootTarget(CCNode* pNode){
	shootTarget = pNode;
}