#pragma once
#include <memory>
#include <vector>
#include "CharacterParameter.h"

class CharacterAbstract
{
protected:
	CharacterParameter									parameter;			//�p�����[�^�[
	std::vector<std::shared_ptr<CharacterAbstract>>		createdCharacter;	//���������L�����N�^�[���i�[����

public:
	CharacterAbstract(CharacterID ID, float priority);
	virtual ~CharacterAbstract() = default;
	virtual void Update(const std::vector<std::unique_ptr<ROCharacterParameter>>& data) = 0;
	virtual void Draw() = 0;

	const CharacterParameter& GetParameter() const;
	const std::vector<std::shared_ptr<CharacterAbstract>>* const GetCreatedCharacter() const;

protected:
	void ClearCreatedCharacter();
};