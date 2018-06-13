#include <memory>
#include "DxLib.h"
#include "InputState.h"
#include "CharacterFactory.h"

#include "Character_Player.h"

//-----------------------------------------------------------------------------
Character_Player::Character_Player(const ImageData& imageData, const Math::Vec2& pos):
	CharacterAbstract(CharacterID::Player, 0.1f),
	imageDrawer(imageData, Math::Vec2((float)imageData.size.w / 2, (float)imageData.size.h / 2), false)
{
	parameter.UseState(State::Active);
	parameter.UseMove(pos, Math::Vec2(0, 0), 0, 0);
	parameter.UseHitBase(-12, -8, 18, 16);
	parameter.hitBase->Offset(parameter.move->GetPos());
}

//-----------------------------------------------------------------------------
void Character_Player::Update(const std::vector<std::unique_ptr<ROCharacterParameter>>& data)
{
	CharacterAbstract::ClearCreatedCharacter();

	parameter.move->ClearMoveVec();

	ControllPlayer();

	parameter.move->UpdatePos();

	ShotBullet();

	parameter.hitBase->Offset(parameter.move->GetPos());
}

//-----------------------------------------------------------------------------
void Character_Player::Draw()
{
	imageDrawer.Draw(parameter.move->GetPos(), 1.0f, 0.f, false);
}


//プレイヤーをジョイパッドで操作する
void Character_Player::ControllPlayer()
{
	if (Input::joypad1.GetVolumeStickL() > 0.f)
	{
		parameter.move->SetAngle(Input::joypad1.GetAngleStickL());
		parameter.move->SetVolume(8.f);
		parameter.move->AddAngleMoveVec();
	}
}

//ボタン入力で弾を発射する
void Character_Player::ShotBullet()
{
	if (Input::joypad1[PAD_INPUT_1].GetDurationTime(ON) % 3 == 0)
	{
		CharacterFactory fac;
		createdCharacter.emplace_back(
			fac.CreateNomalBullet(
				CharacterID::PlayerBullet,
				Image::imageLoader.GetImageData(ImageName::NomalBulletImage),
				Math::ToRadian(0.f),
				30.f,
				parameter.move->GetPos() + Math::Vec2(40, 0)
			)
		);
	}
}