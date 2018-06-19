#pragma once
#include "CharacterDatabase.h"
#include "CharacterAbstract.h"
typedef bool(*Behavior)(CharacterAbstract&);

//�U�镑���֐�
namespace BF
{
	//��ʊO�ɏo���玩�g���폜����
	bool WindowOutDelete(CharacterAbstract& chara);

	//�V���v���Ɉړ�������
	bool NomalMove(CharacterAbstract& chara);

	//�W���C�p�b�h�ő��삷��
	bool ControllJpad(CharacterAbstract& chara);

	//�v���C���[�p�ʏ�e�𐶐�����
	bool CreateNomalBulletForPlayer(CharacterAbstract& chara);

	//y�������ɂӂ�ӂ킵�Ȃ���ړ�����
	bool MoveFuwaFuwa(CharacterAbstract& chara);
}

//����֐�
namespace HC
{
	bool HitCheckCharacter(int characterID, CharacterAbstract& chara, const ROD& data);
}