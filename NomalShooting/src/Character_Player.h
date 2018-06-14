#pragma once
#include "ImageDrawer.h"
#include "Behavior.h"
#include "CharacterAbstract.h"

class Character_Player : public CharacterAbstract
{
private:
	ImageDrawer imageDrawer;

public:
	//優先度、画像データ、初期座標を設定
	Character_Player(const ImageData& imageData, const Math::Vec2& setPos);
	void Update(const std::vector<std::unique_ptr<ROCharacterParameter>>& data) override;
	void Draw() override;
};