#include "GameEnemyBullet.h"
#include "GameHeroBullet.h"
#include "GameHero.h"
void GameEnemyBullet::onEnter(){
	CCNode::onEnter();
}
void GameEnemyBullet::enemyBulletType1(int i, Point enemyPos, Point targetPoint){
	Size winSize = Director::getInstance()->getWinSize();
	auto enemyBullet = GameHeroBullet::create();
	enemyBullet->setType(30);
	enemyBullet->setPosition(enemyPos.x, enemyPos.y-20);
	auto move1 = MoveTo::create(1.0f, Point(enemyPos.x, winSize.height-enemyPos.y / 4));
	auto move2 = MoveTo::create(15.0f, Point(
		enemyPos.x + cos(18 * i - 180) * 1000,
		winSize.height-enemyPos.y / 4 + sin(18 * i - 180) * 1000));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(GameHeroBullet::removeBullet, enemyBullet));
	auto sequence = Sequence::create(move1, move2, actionDone, NULL);
	enemyBullet->runAction(sequence);
	addChild(enemyBullet, 3);
}
void GameEnemyBullet::enemyBulletType2(int i, Point enemyPos,Point targetPoint){
	Size winSize = Director::getInstance()->getWinSize();
	auto enemyBullet = GameHeroBullet::create();
	enemyBullet->setType(31);
	enemyBullet->setPosition(enemyPos.x,enemyPos.y -20);
	/*extern GameHero* myHero;
	auto heroPos = myHero->getPosition();*/
	i = i - 2;
	auto move1 = MoveTo::create(0.5f, Point(enemyPos.x, enemyPos.y-100));
	auto move2 = MoveTo::create(2.0f, Point(enemyPos.x, enemyPos.y-150));
	//auto move3 = MoveTo::create(0.5f, Point(enemyPos.x- i * 50,enemyPos.y-150));
	auto move4 = MoveTo::create(3.0f-0.15f*i, Point(targetPoint.x,targetPoint.y));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(GameHeroBullet::removeBullet, enemyBullet));
	auto sequence = Sequence::create(move1, move2,move4, actionDone, NULL);
	enemyBullet->runAction(sequence);
	addChild(enemyBullet, 3);
}
void GameEnemyBullet::enemyBulletType3(int i, Point enemyPos, Point targetPoint){

}

void GameEnemyBullet::setEnemyBulletType(int flag, Point enemyPos, Point targetPoint){
	switch (flag){
	case 1:
		for (int i = 0; i < 20; i++)
			enemyBulletType1(i,enemyPos,targetPoint);
		break;
	case 2:
		for (int i = 0; i < 5; i++)
			enemyBulletType2(i, enemyPos,targetPoint);
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;

	}
}
void GameEnemyBullet::setType(int flag){
	switch (flag){
	case 30:
		break;
	case 31:
		break;
	case 32:
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
		this->setTag(flag);
	}
}