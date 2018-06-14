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
	BF::ControllJpad(*this);
	parameter.move->NotScreenOutUpdatePos((*parameter.hitBase));

	BF::CreateNomalBulletForPlayer(*this);

	parameter.hitBase->Offset(parameter.move->GetPos());
}

//-----------------------------------------------------------------------------
void Character_Player::Draw()
{
	imageDrawer.Draw(parameter.move->GetPos(), 1.0f, 0.f, false);
}