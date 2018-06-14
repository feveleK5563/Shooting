#include "DxLib.h"

#include "ImageDrawer.h"

//�R���X�g���N�^(�`�悵�����摜�f�[�^�ƃ��[�v���邩�ۂ����w��)
ImageDrawer::ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop):
	imageData(imageData),
	criterionPos(criterionPos),
	nowAnimImage(0),
	animWaitTime(0),
	isLoop(isLoop) {}

//�A�j���[�V����������
void ImageDrawer::Run()
{
	nowAnimImage += 1.0f / animWaitTime;

	if (nowAnimImage > imageData.sheetNum - 1)
	{
		if (isLoop == true)
		{
			nowAnimImage = 0;
		}
		else
		{
			nowAnimImage = imageData.sheetNum - 1.f;
		}
	}
}

//�`�悷��
void ImageDrawer::Draw(const Math::Vec2& pos, float scale, float angle, bool isTurn)
{
	DrawRotaGraph2F(
		pos.x, pos.y,
		criterionPos.x, criterionPos.y,
		(double)scale,
		(double)angle,
		imageData.handle[(int)nowAnimImage],
		true,
		isTurn,
		false);
}

//�ꖇ�����`�悷��(�A�j���[�V�������Ȃ�)
void ImageDrawer::DrawOne(const Math::Vec2& pos, float scale, float angle, bool isTurn, int imageSheet)
{
	DrawRotaGraph2F(
		pos.x, pos.y,
		criterionPos.x, criterionPos.y,
		(double)scale,
		(double)angle,
		imageData.handle[imageSheet],
		true,
		isTurn,
		false);
}

//�摜�f�[�^���擾
const ImageData& ImageDrawer::GetImageData() const
{
	return imageData;
}