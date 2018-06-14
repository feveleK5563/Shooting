#include "Character_Bullet.h"
#include "CharacterFactory.h"
#include "System.h"

//-----------------------------------------------------------------------------
Character_Bullet::Character_Bullet(CharacterID ID, ImageData imageData, float angle, float moveVolume, Math::Vec2 pos):
	CharacterAbstract(ID, 0.2f),
	imageDrawer(imageData, Math::Vec2(imageData.size.w / 2.f, imageData.size.h / 2.f), false)
{
	parameter.UseState(State::Active);
	parameter.UseMove(pos, Math::Vec2(0, 0), angle, moveVolume);
	parameter.UseHitBase(-8, -4, 16, 8);
	parameter.hitBase->Offset(parameter.move->GetPos());
}

//-----------------------------------------------------------------------------
void Character_Bullet::Update(const std::vector<std::unique_ptr<ROCharacterParameter>>& data)
{
	parameter.move->ClearMoveVec();
	parameter.move->AddAngleMoveVec();
	parameter.move->UpdatePos();

	//画面外に出たら削除
	if (BF::WindowOutDelete(*this)) return;

	//(仮)プレイヤーと接触したら消滅
	/*parameter.hitBase->Offset(parameter.move->GetPos());
	for (auto it = data.begin();
		it != data.end();
		++it)
	{
		if ((*(*it)->ID) == CharacterID::Player)
		{
			if (parameter.hitBase->Hit((*(*it)->hitBase)))
			{
				(*parameter.state) = State::Delete;
				return;
			}
		}
	}*/

	parameter.hitBase->Offset(parameter.move->GetPos());
}

//-----------------------------------------------------------------------------
void Character_Bullet::Draw()
{
	imageDrawer.Draw(parameter.move->GetPos(), 1.f, parameter.move->GetAngle(), false);
}