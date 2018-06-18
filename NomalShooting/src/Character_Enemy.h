#pragma once
#include "CharacterAbstract.h"
#include "ImageDrawer.h"
#include "Behavior.h"

class Character_Enemy : public CharacterAbstract
{
private:
	ImageDrawer imageDrawer;
	Behavior	motion;

public:
	Character_Enemy(float priority, 
					int life, 
					Behavior motion, 
					const ImageData& imageData, 
					const Math::Vec2& pos, 
					const Color& color);
	void Update(const ROD& data) override;
	void Draw() override;
};