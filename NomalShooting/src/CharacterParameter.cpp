#include "CharacterParameter.h"

//-----------------------------------------------------------------------------
//�p�����[�^�[�\����(�g�p����l�̎��̂𐶐����Ă���g�p����)
CharacterParameter::CharacterParameter(CharacterID ID, float priority):
	ID(std::make_shared<CharacterID>(ID)),
	priority(std::make_shared<float>(priority)),
	state(nullptr),
	move(nullptr),
	hitBase(nullptr),
	createdNum(std::make_shared<unsigned int>(0)) {}

void CharacterParameter::UseState(const State& state)
{
	this->state = std::make_shared<State>(state);
}

void CharacterParameter::UseMove(	const Math::Vec2&	pos,
									const Math::Vec2&	moveVec,
									float				angle,
									float				moveVolume)
{
	this->move = std::make_shared<Move>(pos, moveVec, angle, moveVolume);
}

void CharacterParameter::UseHitBase(int x, int y, int w, int h)
{
	this->hitBase = std::make_shared<Math::Box2D>(x, y, w, h);
}

//-----------------------------------------------------------------------------
//�ǂݎ���p�p�����[�^�[�\����
ROCharacterParameter::ROCharacterParameter(const CharacterParameter& character) :
	ID(character.ID),
	priority(character.priority),
	state(character.state),
	move(character.move),
	hitBase(character.hitBase) {}