#include "Behavior.h"

//�V���v���Ɉړ�������
bool BF::NomalMove(CharacterAbstract& chara, const ROD& data)
{
	chara.GetParameterRef().move->AddAngleMoveVec();
	return true;
}