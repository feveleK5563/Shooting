#include <memory>
#include "DxLib.h"
#include "InputState.h"
#include "CharacterFactory.h"

#include "Character_Player.h"

//-----------------------------------------------------------------------------
Character_Player::Character_Player(float priority, const ImageData& imageData, const Math::Vec2& pos):
	CharacterAbstract(CharacterID::Player, priority, State::Active),
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
	parameter.objParam->move.ClearMoveVec();
	BF::ControllJpad(*this);
	parameter.objParam->move.NotScreenOutUpdatePos(parameter.objParam->hitBase);

	if (Input::joypad1[PAD_INPUT_1].GetDurationTime(ON) % 3 == 0)
	{
		BF::CreateNomalBulletForPlayer(*this);
	}

	parameter.objParam->hitBase.Offset(parameter.objParam->move.GetPos());
}

//-----------------------------------------------------------------------------
void Character_Player::Draw()
{
	imageDrawer.Draw(parameter.objParam->move.GetPos(), 1.0f, 0.f, false);
}