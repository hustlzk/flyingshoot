#include "cocos2d.h"
USING_NS_CC;
//敌人子弹暂时继承此类
class GameHeroBullet :public CCNode{
public:
	CREATE_FUNC(GameHeroBullet);
	virtual void onEnter();
public:
	//GameHeroBullet(void);
	//virtual ~GameHeroBullet();
	void removeBullet(Node *pNode);//子弹消失
	Vector <Sprite *>& GetBullet();
	void selectSpeed(int flag); //子弹速度
	void setType(int flag);
	int getFlySpeed();
public:
	CCSprite* heroBullet;
	Vector<Sprite*>vecBullet;
	Node* heroPlane;
private:
	bool isvisible; //子弹是否在使用
	int flySpeed = 1000;
};