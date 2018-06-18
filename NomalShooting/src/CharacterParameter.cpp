#include "CharacterParameter.h"

//-----------------------------------------------------------------------------
//オブジェクト(プレイヤーとか敵とかを指す)に使用するパラメーター
ObjectParameter::ObjectParameter() :
	life(0),
	move(),
	hitBase(0, 0, 0, 0) {}

//-----------------------------------------------------------------------------
//パラメーター構造体
CharacterParameter::CharacterParameter(CharacterID ID, float priority, State state):
	ID(std::make_shared<CharacterID>(ID)),
	priority(std::make_shared<float>(priority)),
	createdNum(std::make_shared<unsigned int>(0)),
	state(std::make_shared<State>(state)),
	timeCnt(std::make_shared<TimeCounter>()),
	objParam(nullptr){}

void CharacterParameter::UseObjectParameter()
{
	objParam = std::make_shared<ObjectParameter>();
}

//-----------------------------------------------------------------------------
//読み取り専用パラメーター構造体
ROCharacterParameter::ROCharacterParameter(const CharacterParameter& character) :
	ID(character.ID),
	priority(character.priority),
	createdNum(character.createdNum),
	state(character.state),
	objParam(character.objParam){}