#include "Behavior.h"

//��ʊO�ɏo���玩�g���폜����
bool BF::WindowOutDelete(CharacterAbstract& chara)
{
	if (System::WindowOutBox((*chara.GetParameterRef().hitBase)))
	{
		(*chara.GetParameterRef().state) = State::Delete;
		return true;
	}
	return false;
}