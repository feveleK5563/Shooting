#pragma once
#include "ImageDrawer.h"
#include "Behavior.h"
#include "CharacterAbstract.h"

class Character_Bullet : public CharacterAbstract
{
private:
	ImageDrawer imageDrawer;
	CharacterID hitID;

public:
	//id�A�D��x�A�X���A�ړ��ʁA���W�A�F��ݒ�
	Character_Bullet(CharacterID ID, CharacterID hitID, ImageData imageData, float angle, float moveVolume, Math::Vec2 pos, int R, int G, int B);
	void Update(const ROD& data) override;
	void Draw() override;
};