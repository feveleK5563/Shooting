#pragma once
#include <vector>
#include <memory>
#include "CharacterParameter.h"
typedef std::vector<std::unique_ptr<ROCharacterParameter>> ROD; //ReadOnlyData

//�L�����N�^�[����p�����[�^�[���󂯎��A
//���̃L�����N�^�[�ɂ��̃p�����[�^�[���Q�Ƃ�����
class CharacterDatabase
{
private:
	std::vector<std::unique_ptr<ROCharacterParameter>> data;

public:
	void AddCharacterData(const CharacterParameter& parameter);	//�f�[�^��ǉ�����
	void ClearCharacterData();	//�ێ����Ă���f�[�^��S�č폜����
	const ROD& GetCharacterData();	//�f�[�^�̂܂Ƃ߂�Ԃ�
	void DrawRectAngle();	//�f�[�^�����`�𒲂ׂĕ`�悷��
};