#include "Behavior.h"

bool BF::NomalMove(CharacterAbstract& chara, const ROD& data)
{
	chara.GetParameterRef().objParam->move.AddAngleMoveVec();
	return false;
}