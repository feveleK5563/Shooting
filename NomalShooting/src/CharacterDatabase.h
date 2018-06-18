#pragma once
#include <vector>
#include <memory>
#include "CharacterParameter.h"
typedef std::vector<std::shared_ptr<ROCharacterParameter>> ROD; //ReadOnlyData

//�L�����N�^�[����p�����[�^�[���󂯎��A
//���̃L�����N�^�[�ɂ��̃p�����[�^�[���Q�Ƃ�����
class CharacterDatabase
{
private:
	ROD data;

public:
	void AddCharacterData(const CharacterParameter& parameter);	//�f�[�^��ǉ�����
	void ClearCharacterData();	//�ێ����Ă���f�[�^��S�č폜����
	const ROD& GetCharacterData();	//�f�[�^�̂܂Ƃ߂�Ԃ�
	void DrawHitBase();	//�f�[�^���瓖���蔻���`�𒲂ׂĕ`�悷��
};