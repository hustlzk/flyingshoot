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
	//������Ӧ	
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);
	CCNode* getCurrentPosition();
	void addBulletAmount();   //�����ӵ�
	void initBulletAmount();	//��ʼ���ӵ�����
	void addLife();		//��������ֵ
	void minusLife();   //��������ֵ
	void initLife();	//��ʼ������ֵ
	void beShooted();   //������
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
