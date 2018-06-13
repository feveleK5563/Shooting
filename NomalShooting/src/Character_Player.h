#pragma once
#include "ImageDrawer.h"
#include "CharacterAbstract.h"

class Character_Player : public CharacterAbstract
{
private:
	ImageDrawer imageDrawer;

public:
	//�D��x�A�摜�f�[�^�A�������W��ݒ�
	Character_Player(const ImageData& imageData, const Math::Vec2& setPos);
	void Update(const std::vector<std::unique_ptr<ROCharacterParameter>>& data) override;
	void Draw() override;

private:
	void ControllPlayer();	//�v���C���[���W���C�p�b�h�ő��삷��
	void ShotBullet();		//�{�^�����͂Œe�𔭎˂���
};