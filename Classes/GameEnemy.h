#include "cocos2d.h"
USING_NS_CC;
class GameEnemy :public CCNode{
public:
	CREATE_FUNC(GameEnemy);
	virtual void onEnter();
public:
	CCSprite* enemy;
	/*void update(float dt) override;*/
	void releaseBullet();
	void setEnemyType(int flag);
	void dead(Node *pNode);
	void releaseBullet(int flag);
	void setScene(CCNode*p);
	void setShootTarget(CCNode *pNode);
	/*void randMove(GameEnemy *pNode);*/
private:
	static CCNode* scene;
	static CCNode* shootTarget;
};