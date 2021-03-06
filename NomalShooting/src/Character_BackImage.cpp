#include <memory>
#include "DxLib.h"
#include "InputState.h"
#include "System.h"

#include "Character_BackImage.h"

//画像データ、移動量、無限スクロールするか否かを設定
Character_BackImage::Character_BackImage(float priority, const ImageData& imageData, const Math::Vec2& moveVec, bool isInfinite):
	CharacterAbstract(CharacterID::BackGround, priority, State::Active),
	imageDrawer(imageData, Math::Vec2(0, 0), false),
	isInfinite(isInfinite)
{
	parameter.UseObjectParameter();
	parameter.objParam->move.AddMoveVec(moveVec);
}

void Character_BackImage::Update(const ROD& data)
{
	//座標を移動
	parameter.objParam->move.UpdatePos();

	//isInfiniteがtrueなら無限スクロールさせる
	if (isInfinite)
	{
		InfiniteScroll();
	}
}

void Character_BackImage::Draw()
{
	imageDrawer.Draw(parameter.objParam->move.GetPos(), 1.f, 0.f, false);
	
	if (isInfinite)
	{
		imageDrawer.Draw(parameter.objParam->move.GetPos() +
			Math::Vec2(-(float)imageDrawer.GetImageData().size.w, 0),
			1.f,
			0.f,
			false);

		imageDrawer.Draw(parameter.objParam->move.GetPos() +
			Math::Vec2(0, -(float)imageDrawer.GetImageData().size.h),
			1.f,
			0.f,
			false);

		imageDrawer.Draw(parameter.objParam->move.GetPos() +
			Math::Vec2(	-(float)imageDrawer.GetImageData().size.w,
						-(float)imageDrawer.GetImageData().size.h),
			1.f,
			0.f,
			false);
	}
}


//無限スクロールさせるための処理
void Character_BackImage::InfiniteScroll()
{
	Math::Box2D offsetRect = imageDrawer.GetImageData().size.OffsetCpy(parameter.objParam->move.GetPos());

	if (offsetRect.x < 0)
	{
		parameter.objParam->move.SetPosX((float)System::windowSizeX - 1);
	}
	if (offsetRect.y < 0)
	{
		parameter.objParam->move.SetPosY((float)System::windowSizeY - 1);
	}
	if (offsetRect.x >= System::windowSizeX)
	{
		parameter.objParam->move.SetPosX(0);
	}
	if (offsetRect.y >= System::windowSizeY)
	{
		parameter.objParam->move.SetPosY(0);
	}
}