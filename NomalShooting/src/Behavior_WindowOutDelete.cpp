#include "System.h"

#include "Behavior.h"

//��ʊO�ɏo���玩�g���폜����
bool BF::WindowOutDelete(CharacterAbstract& chara, const ROD& data)
{
	if (System::WindowOutBox(chara.GetParameterRef().objParam->hitBase))
	{
		*chara.GetParameterRef().state = State::Delete;
		return true;
	}
	return false;
}