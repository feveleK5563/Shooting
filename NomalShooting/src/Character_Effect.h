#pragma once
#include "CharacterAbstract.h"

class Character_Effect : public CharacterAbstract
{
private:
	ImageDrawer imageDrawer;

public:
	Character_Effect(float priority, const ImageData& imageData, const Math::Vec2& pos);
	void Update(const ROD& data) override;
	void Draw() override;
};