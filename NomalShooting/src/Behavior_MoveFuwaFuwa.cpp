#include "Behavior.h"

bool BF::MoveFuwaFuwa(CharacterAbstract& chara)
{
	//ふわふわ
	chara.GetParameterRef().objParam->move.ClearMoveVec();
	chara.GetParameterRef().objParam->move.AddMoveVec(
		Math::Vec2(0, 
			sin(Math::ToRadian(chara.GetParameterRef().objParam->move.GetPos().x / 1.5f)) * 40)
	);
	chara.GetParameterRef().objParam->move.UpdateBasePos();

	//左に移動
	chara.GetParameterRef().objParam->move.ClearMoveVec();
	chara.GetParameterRef().objParam->move.AddMoveVec(Math::Vec2(-6, 0));
	chara.GetParameterRef().objParam->move.UpdatePos();

	chara.GetParameterRef().objParam->move;
	return false;
}