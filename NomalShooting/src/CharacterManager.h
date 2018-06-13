#pragma once
#include <memory>
#include <vector>
#include "CharacterParameter.h"
#include "CharacterAbstract.h"
#include "CharacterDatabase.h"

//�O���Ő������ꂽ�L�����N�^�[��o�^���A�Ǘ�����
class CharacterManager
{
private:
	//�L�����N�^�[
	std::vector<std::shared_ptr<CharacterAbstract>> character;
	//�L�����N�^�[�̃p�����[�^�[���󂯎��A�e�L�����N�^�[�ɎQ�Ƃ�����
	CharacterDatabase database;

	//priority(�D��x)�Ń\�[�g�������
	static bool SortAsc(const std::shared_ptr<CharacterAbstract>& left, 
						const std::shared_ptr<CharacterAbstract>& right);

	//�X�e�[�^�X�����āA��Ԃ�Delete�̃L�����N�^�[���폜�������
	static bool RemoveStateDelete(const std::shared_ptr<CharacterAbstract>& chara);

public:
	void SetCharacter(const std::shared_ptr<CharacterAbstract>& set);	//�����Ɏw�肵���I�u�W�F�N�g��o�^����
	void SortCharacter();	//�L�����N�^�[��priority���Ƀ\�[�g����
	void AllUpdate();		//�S�ẴL�����N�^�[�̍X�V���s��
	void AllDraw();			//�S�ẴL�����N�^�[�̕`����s��
};