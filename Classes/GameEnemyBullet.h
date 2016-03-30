#include "cocos2d.h"
USING_NS_CC;
class GameEnemyBullet :public CCNode{
public:
	CREATE_FUNC(GameEnemyBullet);
	virtual void onEnter();
public:
	void setEnemyBulletType(int flag,Point enemyPos,Point targetPoint);
	void enemyBulletType1(int i, Point enemyPos, Point targetPoint);
	void enemyBulletType2(int i, Point enemyPos, Point targetPoint);
	void enemyBulletType3(int i, Point enemyPos, Point targetPoint);
	void enemyBulletType4(int i, Point enemyPos, Point targetPoint);
	void enemyBulletType5(int i, Point enemyPos, Point targetPoint);
	void enemyBulletType6(int i, Point enemyPos, Point targetPoint);
	void setType(int flag);
private:
	int flySpeed1 = 50;
	int flySpeed2 = 100;
	int flySpeed3 = 150;
	int flySpeed4 = 200;
	int flySpeed5 = 250;
};