#pragma once
#include "ImageDrawer.h"
#include "Behavior.h"
#include "CharacterAbstract.h"

class Character_Bullet : public CharacterAbstract
{
private:
	ImageDrawer imageDrawer;

public:
	//id、優先度、傾き、移動量、座標を設定
	Character_Bullet(CharacterID ID, ImageData imageData, float angle, float moveVolume, Math::Vec2 setPos);
	void Update(const ROD& data) override;
	void Draw() override;
};