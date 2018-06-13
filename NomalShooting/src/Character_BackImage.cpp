#include <memory>
#include "DxLib.h"
#include "InputState.h"
#include "System.h"

#include "Character_BackImage.h"

//�摜�f�[�^�A�ړ��ʁA�����X�N���[�����邩�ۂ���ݒ�
Character_BackImage::Character_BackImage(const ImageData& imageData, const Math::Vec2& moveVec, bool isInfinite):
	CharacterAbstract(CharacterID::BackGround, 0.f),
	imageDrawer(imageData, Math::Vec2(0, 0), false),
	isInfinite(isInfinite)
{
	parameter.UseState(State::Active);
	parameter.UseMove(Math::Vec2(0, 0), moveVec, 0, 0);
}

void Character_BackImage::Update(const std::vector<std::unique_ptr<ROCharacterParameter>>& data)
{
	//���W���ړ�
	parameter.move->UpdatePos();

	//isInfinite��true�Ȃ疳���X�N���[��������
	if (isInfinite)
	{
		InfiniteScroll();
	}
}

void Character_BackImage::Draw()
{
	imageDrawer.Draw(parameter.move->GetPos(), 1.f, 0.f, false);
	
	if (isInfinite)
	{
		imageDrawer.Draw(parameter.move->GetPos() + 
			Math::Vec2(-(float)imageDrawer.GetImageData().size.w, 0),
			1.f,
			0.f,
			false);

		imageDrawer.Draw(parameter.move->GetPos() + 
			Math::Vec2(0, -(float)imageDrawer.GetImageData().size.h),
			1.f,
			0.f,
			false);

		imageDrawer.Draw(parameter.move->GetPos() + 
			Math::Vec2(	-(float)imageDrawer.GetImageData().size.w,
						-(float)imageDrawer.GetImageData().size.h),
			1.f,
			0.f,
			false);
	}
}


//�����X�N���[�������邽�߂̏���
void Character_BackImage::InfiniteScroll()
{
	Math::Box2D offsetRect = imageDrawer.GetImageData().size.OffsetCpy(parameter.move->GetPos());

	if (offsetRect.x < 0)
	{
		parameter.move->SetPosX((float)System::windowSizeX - 1);
	}
	if (offsetRect.y < 0)
	{
		parameter.move->SetPosY((float)System::windowSizeY - 1);
	}
	if (offsetRect.x >= System::windowSizeX)
	{
		parameter.move->SetPosX(0);
	}
	if (offsetRect.y >= System::windowSizeY)
	{
		parameter.move->SetPosY(0);
	}
}