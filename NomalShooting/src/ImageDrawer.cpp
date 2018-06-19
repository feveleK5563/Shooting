#include "DxLib.h"

#include "ImageDrawer.h"

Color::Color(): r(255), g(255), b(255){}

Color::Color(int r, int g, int b): r(r), g(g), b(b){}

Color::Color(const Color& color): r(color.r), g(color.g), b(color.b){}

//-----------------------------------------------------------------------------

//�R���X�g���N�^(�`�悵�����摜�f�[�^�ƃ��[�v���邩�ۂ����w��)
ImageDrawer::ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop):
	imageData(imageData),
	criterionPos(criterionPos),
	nowAnimImage(0),
	animWaitTime(0),
	isLoop(isLoop){}

//�R���X�g���N�^(�`�悵�����摜�f�[�^�ƃ��[�v���邩�ۂ����w��)
ImageDrawer::ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop, const Color& color) :
	imageData(imageData),
	criterionPos(criterionPos),
	nowAnimImage(0),
	animWaitTime(0),
	isLoop(isLoop),
	color(color){}

//�A�j���[�V����������
bool ImageDrawer::Run()
{
	if (nowAnimImage >= imageData.sheetNum)
	{
		if (isLoop)
		{
			nowAnimImage = 0;
		}
		return true;
	}

	nowAnimImage += 1.0f / animWaitTime;
	return false;
}

//�`�悷��
void ImageDrawer::Draw(const Math::Vec2& pos, float scale, float angle, bool isTurn)
{
	SetDrawBright(color.r, color.g, color.b);

	DrawRotaGraph2F(
		pos.x, pos.y,
		criterionPos.x, criterionPos.y,
		(double)scale,
		(double)angle,
		imageData.handle[(int)nowAnimImage],
		true,
		isTurn,
		false);

	SetDrawBright(255, 255, 255);
}

//�w��ԍ��̉摜��`�悷��(�A�j���[�V�������Ȃ�)
void ImageDrawer::DrawOne(const Math::Vec2& pos, float scale, float angle, bool isTurn, int imageSheet)
{
	SetDrawBright(color.r, color.g, color.b);

	DrawRotaGraph2F(
		pos.x, pos.y,
		criterionPos.x, criterionPos.y,
		(double)scale,
		(double)angle,
		imageData.handle[imageSheet],
		true,
		isTurn,
		false);

	SetDrawBright(255, 255, 255);
}

//�摜�f�[�^���擾
const ImageData& ImageDrawer::GetImageData() const
{
	return imageData;
}