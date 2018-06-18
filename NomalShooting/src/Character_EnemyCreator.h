#pragma once
#include <random>
#include "CharacterAbstract.h"
#include "TimeCounter.h"

class Character_EnemyCreator : public CharacterAbstract
{
private:
	std::random_device rd;
	std::mt19937 mtrand;

public:
	Character_EnemyCreator(float priority);
	void Update(const ROD& data) override;
	void Draw() override;
};