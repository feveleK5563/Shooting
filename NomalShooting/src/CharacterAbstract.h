#pragma once
#include <memory>
#include <vector>
#include "CharacterParameter.h"
#include "CharacterDatabase.h"

class CharacterAbstract
{
protected:
	CharacterParameter									parameter;			//�p�����[�^�[
	std::vector<std::shared_ptr<CharacterAbstract>>		createdCharacter;	//���������L�����N�^�[���i�[����

public:
	CharacterAbstract(CharacterID ID, float priority, State state);
	virtual ~CharacterAbstract() = default;
	virtual void Update(const ROD& data) = 0;
	virtual void Draw() = 0;

	const CharacterParameter& GetParameterRef();
	std::vector<std::shared_ptr<CharacterAbstract>>& GetCreatedCharacterRef();
	void ClearCreatedCharacter();

	//void Message(int type, const void* data);
};