#include "GameBonus.h"
void GameBonus::onEnter(){
	CCNode::onEnter();
	this->setContentSize(CCSizeMake(21, 52));
	addChild(bonus, 2);
}
void GameBonus::setBonusType(int flag){
	switch (flag){
	case 2:
		bonus = CCSprite::create("bonus_fight.png");
		break;
	case 3:
		bonus = CCSprite::create("bonus_food.png");
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;

	}
	setTag(flag);
}
void GameBonus::disappear(CCNode* pNode){
	removeFromParentAndCleanup(pNode);
}
int GameBonus::getFlySpeed(){
	return flySpeed;
}
