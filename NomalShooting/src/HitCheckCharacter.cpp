#include "Behavior.h"

bool HC::HitCheckCharacter(int characterID, CharacterAbstract& chara, const ROD& data)
{
	for (const auto& it : data)
	{
		if ((int)*it->ID & characterID)
		{
			if (chara.GetParameterRef().objParam->hitBase.Hit(it->objParam->hitBase))
			{
				return true;
			}
		}
	}
	return false;
}