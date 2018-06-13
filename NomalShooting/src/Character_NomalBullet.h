#pragma once
#include "ImageDrawer.h"
#include "CharacterAbstract.h"

class Character_NomalBullet : public CharacterAbstract
{
private:
	ImageDrawer imageDrawer;

public:
	//id、優先度、傾き、移動量、座標を設定
	Character_NomalBullet(CharacterID ID, ImageData imageData, float angle, float moveVolume, Math::Vec2 setPos);
	void Update(const std::vector<std::unique_ptr<ROCharacterParameter>>& data) override;
	void Draw() override;
};