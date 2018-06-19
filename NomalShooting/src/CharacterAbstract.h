#pragma once
#include <memory>
#include <vector>
#include "CharacterParameter.h"
#include "CharacterDatabase.h"

class CharacterAbstract
{
protected:
	CharacterParameter									parameter;			//パラメーター
	std::vector<std::shared_ptr<CharacterAbstract>>		createdCharacter;	//生成したキャラクターを格納する

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