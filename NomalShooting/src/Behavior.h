#pragma once
#include "CharacterDatabase.h"
#include "CharacterAbstract.h"
typedef bool(*Behavior)(CharacterAbstract&, const ROD&);

//�U�镑���֐�
namespace BF
{
	//��ʊO�ɏo���玩�g���폜����
	bool WindowOutDelete(CharacterAbstract& chara, const ROD& data);

	//�V���v���Ɉړ�������
	bool NomalMove(CharacterAbstract& chara, const ROD& data);

	//�W���C�p�b�h�ő��삷��
	bool ControllJpad(CharacterAbstract& chara, const ROD& data);

	//�v���C���[�p�ʏ�e�𐶐�����
	bool CreateNomalBulletForPlayer(CharacterAbstract& chara, const ROD& data);

	//y�������ɂӂ�ӂ킵�Ȃ���ړ�����
	bool MoveFuwaFuwa(CharacterAbstract& chara, const ROD& data);
}

//����֐�
namespace HC
{
	bool HitCheckCharacter(int characterID, CharacterAbstract& chara, const ROD& data);
}