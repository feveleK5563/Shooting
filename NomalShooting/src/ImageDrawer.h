#pragma once
#include <vector>
#include "Math.h"
#include "ImageLoader.h"

class ImageDrawer
{
private:
	ImageData	imageData;		//�摜�f�[�^
	Math::Vec2	criterionPos;	//�`��̊�ʒu
	float		nowAnimImage;	//���݂̃A�j���[�V�����摜
	float		animWaitTime;	//�A�j���[�V�����̑ҋ@����
	bool		isLoop;			//�A�j���[�V�����̃��[�v�t���O

public:
	//�R���X�g���N�^(�`�悵�����摜�f�[�^�ƃ��[�v���邩�ۂ����w��)
	ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop);

	void Run();	//�A�j���[�V����������(�s�v�Ȃ�Ă΂Ȃ��Ă��悢)

	void Draw(const Math::Vec2& pos, float scale, float angle, bool isTurn);	//�`�悷��
	void DrawOne(const Math::Vec2& pos, float scale, float angle, bool isTurnint, int imageSheet);	//�ꖇ�����`�悷��

	const ImageData& GetImageData() const;	//�摜�f�[�^���擾
};