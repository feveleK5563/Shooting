#pragma once
#include "ImageDrawer.h"
#include "Behavior.h"
#include "CharacterAbstract.h"

class Character_Player : public CharacterAbstract
{
private:
	ImageDrawer imageDrawer;

public:
	//�D��x�A�摜�f�[�^�A�������W��ݒ�
	Character_Player(float priority, const ImageData& imageData, const Math::Vec2& setPos);
	void Update(const ROD& data) override;
	void Draw() override;
};