#include "GameAllEnemy.h"
#include "GameEnemy.h"
void GameAllEnemy::onEnter(){
	CCNode::onEnter();
}

void GameAllEnemy::randEnemy1(){
	static int left = 1;
	auto enemy = GameEnemy::create();
	enemy->setScene(scene);
	enemy->setShootTarget(shootTarget);
	Size winSize = Director::getInstance()->getWinSize();
	srand((unsigned)time(0)*left);
	int type = 10;
	enemy->setEnemyType(11);
	left = rand() % (int)(winSize.width);
	Point enemyPos = (Point(left, winSize.height - 40));
	enemy->setPosition(enemyPos);
	//float flyDuration = winSize.height / flySpeed2;
	CCActionInterval* actionMove = MoveTo::create(10.0f, Point(enemyPos.x, 0));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(GameEnemy::dead, enemy));
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	enemy->runAction(sequence);
	enemy->releaseBullet(2);
	scene->addChild(enemy, 3);
}
void GameAllEnemy::randEnemy2(){
	static int left = 2;
	auto enemy = GameEnemy::create();
	enemy->setScene(scene);
	enemy->setShootTarget(shootTarget);
	Size winSize = Director::getInstance()->getWinSize();
	srand((unsigned)time(0)*left);
	int type = 10;
	enemy->setEnemyType(10);
	left = rand() % (int)(winSize.width);
	Point enemyPos = (Point(left, winSize.height - 40));
	enemy->setPosition(enemyPos);
	float flyDuration = winSize.height / flySpeed2;
	ccBezierConfig tr0;
	tr0.endPosition = Vec2(left, 30);
	if (left >= winSize.width / 2){
		tr0.controlPoint_1 = Vec2(left - 400, winSize.height / 3 * 2);
		tr0.controlPoint_2 = Vec2(left + 400, winSize.height / 3);
		auto forwardBy = RotateBy::create(flyDuration, -45);
	}
	else{
		tr0.controlPoint_1 = Vec2(left + 400, winSize.height / 3 * 2);
		tr0.controlPoint_1 = Vec2(left - 400, winSize.height / 3);
		auto forwardBy = RotateBy::create(flyDuration, 45);
	}
	auto bezierForward = BezierTo::create(flyDuration, tr0);
	auto forwardBy = RotateBy::create(flyDuration, 180);
	auto spawn = Spawn::create(bezierForward, forwardBy, NULL);
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(GameEnemy::dead, enemy));
	Sequence* sequence = Sequence::create(spawn, actionDone, NULL);
	enemy->runAction(sequence);
	enemy->releaseBullet(1);
	scene->addChild(enemy, 3);
}
void GameAllEnemy::update(float dt){
	randEnemy1();
	randEnemy2();
}
void GameAllEnemy::setScene(CCNode* p){
	scene = p;
}
void GameAllEnemy::enemyAppear(){
	schedule(schedule_selector(GameAllEnemy::update), 2.0f, kRepeatForever, 0);
}
void GameAllEnemy::getShootTarget(CCNode* pNode){
	shootTarget = pNode;
}