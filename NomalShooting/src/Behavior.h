#pragma once
#include "CharacterAbstract.h"
typedef bool(*Behavior)(CharacterAbstract&);

namespace BF
{
	//��ʊO�ɏo���玩�g���폜����
	bool WindowOutDelete(CharacterAbstract& chara);

	//�W���C�p�b�h�ő��삷��
	bool ControllJpad(CharacterAbstract& chara);

	//�v���C���[�p�ʏ�e�𐶐�����
	bool CreateNomalBulletForPlayer(CharacterAbstract& chara);
}