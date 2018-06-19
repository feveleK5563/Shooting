#pragma once
#include <vector>
#include "Math.h"
#include "ImageLoader.h"

//�F�w��
class Color
{
public:
	int r, g, b;
	Color();
	Color(int r, int g, int b);
	Color(const Color& color);
};

//�摜�f�[�^�̕`��ƃA�j���[�V�����̊Ǘ�
class ImageDrawer
{
private:
	ImageData	imageData;		//�摜�f�[�^
	Math::Vec2	criterionPos;	//�`��̊�ʒu
	float		nowAnimImage;	//���݂̃A�j���[�V�����摜
	float		animWaitTime;	//�A�j���[�V�����̑ҋ@����
	bool		isLoop;			//�A�j���[�V�����̃��[�v�t���O
	Color		color;			//RGB(�ԗΐ�)

public:
	//�R���X�g���N�^(�`�悵�����摜�f�[�^�ƃ��[�v���邩�ۂ����w��)
	ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop);
	//�R���X�g���N�^(�`�悵�����摜�f�[�^�ƃ��[�v���邩�ۂ��ƕ`��P�x���w��)
	ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop, const Color& color);
	//�R���X�g���N�^(�`�悵�����摜�f�[�^�ƃA�j���[�V�����̃E�F�C�g���Ԃƃ��[�v���邩�ۂ��ƕ`��P�x���w��)
	ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, float animWaitTime, bool isLoop, const Color& color);

	bool Run();	//�A�j���[�V����������(�A�j���[�V���������������true���Ԃ�)

	void Draw(const Math::Vec2& pos, float scale, float angle, bool isTurn);	//�`�悷��
	void DrawOne(const Math::Vec2& pos, float scale, float angle, bool isTurnint, int imageSheet);	//�w��ԍ��̉摜��`�悷��

	const ImageData& GetImageData() const;	//�摜�f�[�^���擾
};