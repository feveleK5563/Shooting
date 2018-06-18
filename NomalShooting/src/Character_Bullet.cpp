#include "Character_Bullet.h"
#include "CharacterFactory.h"
#include "System.h"

//-----------------------------------------------------------------------------
Character_Bullet::Character_Bullet(	float			priority,
									CharacterID		ID,
									Behavior		moveBehavior,
									int				hitTargetID,
									ImageData		imageData,
									float			angle,
									float			moveVolume,
									Math::Vec2		pos,
									const Color&	color):
	CharacterAbstract(ID, priority, State::Active),
	imageDrawer(imageData, Math::Vec2(imageData.size.w / 2.f, imageData.size.h / 2.f), false, color),
	moveBehavior(moveBehavior),
	hitTargetID(hitTargetID)
{
	parameter.UseObjectParameter();
	parameter.objParam->life = 1;

	parameter.objParam->move.SetPos(pos.x, pos.y);
	parameter.objParam->move.SetAngle(angle);
	parameter.objParam->move.SetVolume(moveVolume);

	parameter.objParam->hitBase = Math::Box2D(-8, -4, 16, 8);
	parameter.objParam->hitBase.Offset(parameter.objParam->move.GetPos());
}

//-----------------------------------------------------------------------------
void Character_Bullet::Update(const ROD& data)
{
	if (*parameter.state == State::Death)
	{
		*parameter.state = State::Delete;
		return;
	}

	parameter.objParam->move.ClearMoveVec();
	moveBehavior(*this, data);
	parameter.objParam->move.UpdatePos();

	//‰æ–ÊŠO‚Éo‚½‚çíœ
	if (BF::WindowOutDelete(*this, data)) return;

	parameter.objParam->hitBase.Offset(parameter.objParam->move.GetPos());

	//‘ÎÛ‚ÆÚG‚µ‚½‚çÁ–Å‚·‚é
	if (HC::HitCheckCharacter(hitTargetID, *this, data))
	{
		*parameter.state = State::Death;
		return;
	}
}

//-----------------------------------------------------------------------------
void Character_Bullet::Draw()
{
	imageDrawer.Draw(parameter.objParam->move.GetPos(), 1.f, parameter.objParam->move.GetAngle(), false);
}