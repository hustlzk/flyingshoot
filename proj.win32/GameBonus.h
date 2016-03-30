#include "cocos2d.h"
USING_NS_CC;
class GameBonus :public CCNode{
public:
	CREATE_FUNC(GameBonus);
	virtual void onEnter();
public:
	CCSprite* bonus;
	void appearBonus();
	void setBonusType(int flag);
	void disappear(CCNode *pNode);
	int getFlySpeed();
private:
	int flySpeed = 100;
};