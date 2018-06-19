#include "DxLib.h"

#include "ImageDrawer.h"

Color::Color(): r(255), g(255), b(255){}

Color::Color(int r, int g, int b): r(r), g(g), b(b){}

Color::Color(const Color& color): r(color.r), g(color.g), b(color.b){}

//-----------------------------------------------------------------------------

//コンストラクタ(描画したい画像データとループするか否かを指定)
ImageDrawer::ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop):
	imageData(imageData),
	criterionPos(criterionPos),
	nowAnimImage(0),
	animWaitTime(0),
	isLoop(isLoop){}

//コンストラクタ(描画したい画像データとループするか否かを指定)
ImageDrawer::ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop, const Color& color) :
	imageData(imageData),
	criterionPos(criterionPos),
	nowAnimImage(0),
	animWaitTime(0),
	isLoop(isLoop),
	color(color){}

//アニメーションさせる
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

//描画する
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

//指定番号の画像を描画する(アニメーションしない)
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

//画像データを取得
const ImageData& ImageDrawer::GetImageData() const
{
	return imageData;
}