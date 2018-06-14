#include "DxLib.h"

#include "ImageDrawer.h"

//コンストラクタ(描画したい画像データとループするか否かを指定)
ImageDrawer::ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop):
	imageData(imageData),
	criterionPos(criterionPos),
	nowAnimImage(0),
	animWaitTime(0),
	isLoop(isLoop) {}

//アニメーションさせる
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

//描画する
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

//一枚だけ描画する(アニメーションしない)
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

//画像データを取得
const ImageData& ImageDrawer::GetImageData() const
{
	return imageData;
}