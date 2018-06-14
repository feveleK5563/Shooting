#pragma once
#include "ImageDrawer.h"
#include "Behavior.h"
#include "CharacterAbstract.h"

class Character_Bullet : public CharacterAbstract
{
private:
	ImageDrawer imageDrawer;

public:
	//id�A�D��x�A�X���A�ړ��ʁA���W��ݒ�
	Character_Bullet(CharacterID ID, ImageData imageData, float angle, float moveVolume, Math::Vec2 setPos);
	void Update(const ROD& data) override;
	void Draw() override;
};