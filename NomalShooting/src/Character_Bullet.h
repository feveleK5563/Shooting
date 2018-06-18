#pragma once
#include "ImageDrawer.h"
#include "Behavior.h"
#include "CharacterAbstract.h"

class Character_Bullet : public CharacterAbstract
{
private:
	ImageDrawer	imageDrawer;
	Behavior	moveBehavior;
	int			hitTargetID;

public:
	Character_Bullet(	float			priority,		//�D��x
						CharacterID		ID,				//���g��ID
						Behavior		moveBehavior,	//����̐U�镑���֐�
						int				hitTargetID,	//�ڐG����p��ID
						ImageData		imageData,		//�摜�f�[�^
						float			angle,			//�X��
						float			moveVolume,		//�ړ���
						Math::Vec2		pos,			//�o�����W
						const Color&	color);			//�F

	void Update(const ROD& data) override;
	void Draw() override;
};