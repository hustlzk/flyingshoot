#include "cocos2d.h"
USING_NS_CC;
class GameHero :public CCNode{
public:
	CREATE_FUNC(GameHero);
	virtual void onEnter();
	virtual void onExit();
public :
	CCSprite* hero;
	void releaseBullet();
	void update(float dt) override;
	void update2(float dt);
	//键盘响应	
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);
	CCNode* getCurrentPosition();
	void addBulletAmount();   //增加子弹
	void initBulletAmount();	//初始化子弹数量
	void addLife();		//增加生命值
	void minusLife();   //减少生命值
	void initLife();	//初始化生命值
	void beShooted();   //被射中
	void dead(CCNode *pNode);
	void setType(int flag,CCSprite *pSprite);
	int level = 1;
	Point currentPos;
	bool isBlink = false;
private:
	int bulletAmount;
	int life;
	bool heroDir[5];
	bool isShoot;
};
