#include "Behavior.h"

//シンプルに移動させる
bool BF::NomalMove(CharacterAbstract& chara, const ROD& data)
{
	chara.GetParameterRef().move->AddAngleMoveVec();
	return true;
}