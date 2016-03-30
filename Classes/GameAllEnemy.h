#include "cocos2d.h"
USING_NS_CC;
class GameAllEnemy :public CCNode
{
public:
	CREATE_FUNC(GameAllEnemy);
	virtual void onEnter();
public:
	/*void randBullet();*/
	void randEnemy1();
	void randEnemy2();
	void update(float dt) override;
	void getShootTarget(CCNode* pNode);
	void setScene(CCNode* p);
	void enemyAppear();
private:
	CCNode* scene;
	CCNode* shootTarget;
	int flySpeed1 = 100;
	int flySpeed2 = 150;
	int flySpeed3 = 200;
};