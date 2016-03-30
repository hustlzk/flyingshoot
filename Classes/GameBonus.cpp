#include "GameBonus.h"
void GameBonus::onEnter(){
	CCNode::onEnter();

}
void GameBonus::setBonusType(int flag){
	switch (flag){
	case 2:
		bonus = CCSprite::create("bonus_fignt.png");
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
}
void GameBonus::disappear(CCNode* pNode){
	removeFromParentAndCleanup(pNode);
}
int GameBonus::getFlySpeed(){
	return flySpeed;
}
void GameBonus::appearBonus(){
	addChild(bonus, 2);
}