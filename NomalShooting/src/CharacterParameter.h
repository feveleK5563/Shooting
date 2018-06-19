#pragma once
#include "Math.h"
#include "Move.h"
#include "ImageDrawer.h"
#include "System.h"
#include "TimeCounter.h"

//�g��
enum struct CharacterID
{
	Non				= 0,		//���ݒ�
	BackGround		= 1 << 0,	//�w�i
	Player			= 1 << 1,	//�v���C���[
	EnemyCreator	= 1 << 2,	//�G������
	Enemy			= 1 << 3,	//�G
	PlayerBullet	= 1 << 4,	//�v���C���[�e
	EnemyBullet		= 1 << 5,	//�G�e
	UI				= 1 << 6,	//UI
	Effect			= 1 << 7,	//�G�t�F�N�g
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

//�I�u�W�F�N�g(�v���C���[�Ƃ��G�Ƃ����w��)�Ɏg�p����p�����[�^�[
class ObjectParameter
{
public:
	int			life;		//�̗�
	Move		move;		//���W�Ɠ���
	Math::Box2D	hitBase;	//�����蔻��

	ObjectParameter();
};

//�p�����[�^�[�\����
struct CharacterParameter
{
	std::shared_ptr<CharacterID>		ID;				//�g��(�K�{)
	std::shared_ptr<float>				priority;		//�D��x(�K�{)
	std::shared_ptr<unsigned int>		createdNum;		//���������L�����N�^�[�̐�(�K�{)
	std::shared_ptr<State>				state;			//���
	std::shared_ptr<TimeCounter>		timeCnt;		//���Ԍv��
	std::shared_ptr<ObjectParameter>	objParam;		//�̂��g�p����p�����[�^�[

	CharacterParameter(CharacterID ID, float priority, State state);
	void UseObjectParameter();
};

//�ǂݎ���p�p�����[�^�[�\����
struct ROCharacterParameter
{
	const std::shared_ptr<const CharacterID>		ID;				//�g��(�K�{)
	const std::shared_ptr<const float>				priority;		//�D��x(�K�{)
	const std::shared_ptr<const unsigned int>		createdNum;		//���������L�����N�^�[�̐�(�K�{)
	const std::shared_ptr<const State>				state;			//���
	const std::shared_ptr<const ObjectParameter>	objParam;		//�̂��g�p����p�����[�^�[

	ROCharacterParameter(const CharacterParameter& character);
};