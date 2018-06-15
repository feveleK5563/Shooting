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
	//id、優先度、傾き、移動量、座標、色を設定
	Character_Bullet(CharacterID ID, CharacterID hitID, ImageData imageData, float angle, float moveVolume, Math::Vec2 pos, int R, int G, int B);
	void Update(const ROD& data) override;
	void Draw() override;
};