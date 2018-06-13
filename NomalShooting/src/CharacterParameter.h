#pragma once
#include "Move.h"
#include "ImageDrawer.h"
#include "System.h"

//�g��
enum struct CharacterID
{
	BackGround,		//�w�i
	Player,			//�v���C���[
	Enemy,			//�G
	PlayerBullet,	//�v���C���[�e
	EnemyBullet,	//�G�e
	UI,				//UI
};

//���
enum struct State
{
	Non,		//���݂Ȃ�
	Ready,		//����
	Active,		//����
	Death,		//���S
	Delete,		//�폜
};

//�p�����[�^�[�\����(�g�p����l�̎��̂𐶐����Ă���g�p����)
struct CharacterParameter
{
	std::shared_ptr<CharacterID>	ID;				//�g��(�K�{)
	std::shared_ptr<float>			priority;		//�D��x(�K�{)
	std::shared_ptr<State>			state;			//���
	std::shared_ptr<Move>			move;			//���W�Ɠ���
	std::shared_ptr<Math::Box2D>	hitBase;		//�����蔻��

	CharacterParameter(CharacterID ID, float priority);

	void UseState(const State& state);
	void UseMove(const Math::Vec2&	pos, const Math::Vec2&	moveVec, float angle, float moveVolume);
	void UseHitBase(int x, int y, int w, int h);
};

//�ǂݎ���p�p�����[�^�[�\����
struct ROCharacterParameter
{
	const std::shared_ptr<const CharacterID>	ID;				//�g��(�K�{)
	const std::shared_ptr<const float>			priority;		//�D��x(�K�{)
	const std::shared_ptr<const State>			state;			//���
	const std::shared_ptr<const Move>			move;			//���W�Ɠ���
	const std::shared_ptr<const Math::Box2D>	hitBase;		//�����蔻��

	ROCharacterParameter(const CharacterParameter& character);
};