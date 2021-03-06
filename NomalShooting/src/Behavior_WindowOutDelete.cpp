#include "System.h"

#include "Behavior.h"

//画面外に出たら自身を削除する
bool BF::WindowOutDelete(CharacterAbstract& chara)
{
	if (System::WindowOutBox(chara.GetParameterRef().objParam->hitBase))
	{
		*chara.GetParameterRef().state = State::Delete;
		return true;
	}
	return false;
}