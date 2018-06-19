#include "Behavior.h"
#include "CharacterFactory.h"

#include "Character_Enemy.h"

//-----------------------------------------------------------------------------
Character_Enemy::Character_Enemy(	float priority, 
									int life,
									Behavior motion,
									const ImageData& imageData,
									const Math::Vec2& pos,
									const Color& color):
	CharacterAbstract(CharacterID::Enemy, priority, State::Active),
	imageDrawer(imageData, Math::Vec2(imageData.size.w / 2.f, imageData.size.h / 2.f), false, color),
	motion(motion)
{
	parameter.UseObjectParameter();
	parameter.objParam->life = life;
	parameter.objParam->move.SetPos(pos.x, pos.y);
	parameter.objParam->hitBase = Math::Box2D(-16, -16, 32, 32);
	parameter.objParam->hitBase.Offset(parameter.objParam->move.GetPos());
}

//-----------------------------------------------------------------------------
void Character_Enemy::Update(const ROD& data)
{
	CharacterAbstract::ClearCreatedCharacter();

	if (*parameter.state == State::Death)
	{
		*parameter.state = State::Delete;
		return;
	}

	parameter.timeCnt->Run();

	motion(*this);

	parameter.objParam->hitBase.Offset(parameter.objParam->move.GetPos());

	if (HC::HitCheckCharacter((int)CharacterID::PlayerBullet, *this, data))
	{
		--parameter.objParam->life;
		if (parameter.objParam->life <= 0)
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
	}
}

//-----------------------------------------------------------------------------
void Character_Enemy::Draw()
{
	imageDrawer.Draw(parameter.objParam->move.GetPos(), 1.f, 0, false);
}