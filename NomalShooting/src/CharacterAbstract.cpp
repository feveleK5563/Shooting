#include "CharacterAbstract.h"

CharacterAbstract::CharacterAbstract(CharacterID ID, float priority) :
	parameter(ID, priority) {}

const CharacterParameter& CharacterAbstract::GetParameterRef()
{
	return parameter;
}

std::vector<std::shared_ptr<CharacterAbstract>>& CharacterAbstract::GetCreatedCharacterRef()
{
	(*parameter.createdNum) = (unsigned int)createdCharacter.size();
	return createdCharacter;
}

void CharacterAbstract::ClearCreatedCharacter()
{
	createdCharacter.clear();
	createdCharacter.shrink_to_fit();
}