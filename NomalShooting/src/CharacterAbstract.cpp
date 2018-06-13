#include "CharacterAbstract.h"

CharacterAbstract::CharacterAbstract(CharacterID ID, float priority) :
	parameter(ID, priority) {}

const CharacterParameter& CharacterAbstract::GetParameter() const
{
	return parameter;
}

const std::vector<std::shared_ptr<CharacterAbstract>>* const CharacterAbstract::GetCreatedCharacter() const
{
	return &createdCharacter;
}

void CharacterAbstract::ClearCreatedCharacter()
{
	createdCharacter.clear();
	createdCharacter.shrink_to_fit();
}