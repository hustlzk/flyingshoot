#include "cocos2d.h"
USING_NS_CC;
//�����ӵ���ʱ�̳д���
class GameHeroBullet :public CCNode{
public:
	CREATE_FUNC(GameHeroBullet);
	virtual void onEnter();
public:
	//GameHeroBullet(void);
	//virtual ~GameHeroBullet();
	void removeBullet(Node *pNode);//�ӵ���ʧ
	Vector <Sprite *>& GetBullet();
	void selectSpeed(int flag); //�ӵ��ٶ�
	void setType(int flag);
	int getFlySpeed();
public:
	CCSprite* heroBullet;
	Vector<Sprite*>vecBullet;
	Node* heroPlane;
private:
	bool isvisible; //�ӵ��Ƿ���ʹ��
	int flySpeed = 1000;
};