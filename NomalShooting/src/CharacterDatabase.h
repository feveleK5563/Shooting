#pragma once
#include <vector>
#include <memory>
#include "CharacterParameter.h"

//�L�����N�^�[����p�����[�^�[���󂯎��A
//���̃L�����N�^�[�ɂ��̃p�����[�^�[�𕪔z����
class CharacterDatabase
{
private:
	std::vector<std::unique_ptr<ROCharacterParameter>> data;

public:
	void AddCharacterData(const CharacterParameter& parameter);	//�f�[�^��ǉ�����
	void ClearCharacterData();	//�ێ����Ă���f�[�^��S�č폜����
	const std::vector<std::unique_ptr<ROCharacterParameter>>& GetCharacterData();	//�f�[�^�̂܂Ƃ߂�Ԃ�
	void DrawRectAngle();	//�f�[�^�����`�𒲂ׂĕ`�悷��
};