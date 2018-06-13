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
	bool showRectAngle;	//�����蔻���`�����t���O

	//�L�����N�^�[
	std::vector<std::shared_ptr<CharacterAbstract>> character;
	//�L�����N�^�[�̃p�����[�^�[���󂯎��A�e�L�����N�^�[�ɎQ�Ƃ�����
	CharacterDatabase database;

public:
	CharacterManager();
	void AddCharacter(const std::shared_ptr<CharacterAbstract>& set);	//�����Ɏw�肵���I�u�W�F�N�g��ǉ�����
	void AllUpdate();		//�S�ẴL�����N�^�[�̍X�V���s��
	void AllDraw();			//�S�ẴL�����N�^�[�̕`����s��

private:
	void GetCharacterParameter();	//�S�ẴL�����N�^�[����p�����[�^�����󂯎��
	void AllCharacterUpdate();		//�S�ẴL�����N�^�[��Update���Ă�
	void GetCreatedCharacter();		//�L�����N�^�[�̍쐬�����L�����N�^�[���󂯎��A�o�^����
	void KillDeleteCharacter();		//��Ԃ�Delete�̃L�����N�^�[���폜����
	void SortCharacter();			//�L�����N�^�[��priority���Ƀ\�[�g����

	//priority(�D��x)�Ń\�[�g�������
	static bool SortAsc(const std::shared_ptr<CharacterAbstract>& left,
		const std::shared_ptr<CharacterAbstract>& right);

	//�X�e�[�^�X�����ď�Ԃ�Delete�̃L�����N�^�[���폜�������
	static bool RemoveStateDelete(const std::shared_ptr<CharacterAbstract>& chara);
};