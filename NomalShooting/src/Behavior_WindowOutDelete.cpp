#include "System.h"

#include "Behavior.h"

//‰æ–ÊŠO‚Éo‚½‚ç©g‚ğíœ‚·‚é
bool BF::WindowOutDelete(CharacterAbstract& chara, const ROD& data)
{
	if (System::WindowOutBox(chara.GetParameterRef().objParam->hitBase))
	{
		*chara.GetParameterRef().state = State::Delete;
		return true;
	}
	return false;
}