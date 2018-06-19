#include <memory>
#include "DxLib.h"
#include "InputState.h"
#include "CharacterFactory.h"

#include "Character_Player.h"

//-----------------------------------------------------------------------------
Character_Player::Character_Player(float priority, const ImageData& imageData, const Math::Vec2& pos):
	CharacterAbstract(CharacterID::Player, priority, State::Ready),
	imageDrawer(imageData, Math::Vec2((float)imageData.size.w / 2, (float)imageData.size.h / 2), false)
{
	parameter.UseObjectParameter();
	parameter.objParam->life = 0;

	parameter.objParam->move.SetPos(pos.x, pos.y);

	parameter.objParam->hitBase = Math::Box2D(-12, -8, 18, 16);
	parameter.objParam->hitBase.Offset(parameter.objParam->move.GetPos());
}

//-----------------------------------------------------------------------------
void Character_Player::Update(const ROD& data)
{
	if (*parameter.state == State::Death)
	{
		*parameter.state = State::Delete;

		CharacterFactory factory;
		createdCharacter.emplace_back(
			factory.CreatePlayer(
				Image::imageLoader.GetImageData(ImageName::PlayerImage),
				Math::Vec2(-30, (float)System::windowSizeY / 2)
			)
		);
		return;
	}

	parameter.timeCnt->Run();

	parameter.objParam->move.ClearMoveVec();
	if (parameter.timeCnt->GetNowCntTime() > 40)
	{
		BF::ControllJpad(*this);
		if (parameter.timeCnt->GetNowCntTime() > 80)
		{
			*parameter.state = State::Active;
		}
		parameter.objParam->move.NotScreenOutUpdatePos(parameter.objParam->hitBase);
	}
	else
	{
		parameter.objParam->move.AddMoveVec(Math::Vec2(5, 0));
		BF::NomalMove(*this);
		parameter.objParam->move.UpdatePos();
	}

	if (Input::joypad1[PAD_INPUT_1].GetDurationTime(ON) % 3 == 0)
	{
		BF::CreateNomalBulletForPlayer(*this);
	}

	if (*parameter.state == State::Active &&
		HC::HitCheckCharacter((int)CharacterID::Enemy | (int)CharacterID::EnemyBullet, *this, data))
	{
		*parameter.state = State::Death;

		CharacterFactory factory;
		createdCharacter.emplace_back(
			factory.CreateEffect(
				Image::imageLoader.GetImageData(ImageName::BombEffect),
				parameter.objParam->move.GetPos()
			)
		);
	}

	parameter.objParam->hitBase.Offset(parameter.objParam->move.GetPos());
}

//-----------------------------------------------------------------------------
void Character_Player::Draw()
{
	if (*parameter.state == State::Ready)
	{
		if (parameter.timeCnt->GetNowCntTime() % 2)
		return;
	}
	imageDrawer.Draw(parameter.objParam->move.GetPos(), 1.0f, 0.f, false);
}