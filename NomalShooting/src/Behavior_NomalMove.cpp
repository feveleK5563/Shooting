#include "Behavior.h"

//ƒVƒ“ƒvƒ‹‚ÉˆÚ“®‚³‚¹‚é
bool BF::NomalMove(CharacterAbstract& chara, const ROD& data)
{
	chara.GetParameterRef().move->AddAngleMoveVec();
	return true;
}