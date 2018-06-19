#include "Behavior.h"

bool BF::NomalMove(CharacterAbstract& chara)
{
	chara.GetParameterRef().objParam->move.AddAngleMoveVec();
	return false;
}