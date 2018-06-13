#include <algorithm>
#include "DxLib.h"
#include "InputState.h"

#include "CharacterManager.h"

CharacterManager::CharacterManager() :
	showRectAngle(false) {}

//-----------------------------------------------
//�����Ɏw�肵���I�u�W�F�N�g��o�^����
void CharacterManager::AddCharacter(const std::shared_ptr<CharacterAbstract>& set)
{
	character.emplace_back(set);
}

//-----------------------------------------------
//�S�ẴL�����N�^�[�̍X�V���s��
void CharacterManager::AllUpdate()
{
	//�S�ẴL�����N�^�[����p�����[�^�����󂯎��
	GetCharacterParameter();

	//�S�ẴL�����N�^�[��Update���Ă�
	AllCharacterUpdate();

	//�e�L�����N�^�[�̍쐬�����f�[�^���󂯎��A�o�^����
	GetCreatedCharacter();

	//��Ԃ�Death�̃L�����N�^�[���ꊇ�폜����
	KillDeleteCharacter();

	//priority���Q�Ƃ��ď����Ƀ\�[�g����
	SortCharacter();

	//���̃R���g���[���L�[���������瓖���蔻�������������
	if (Input::key[KEY_INPUT_LCONTROL] == DOWN)
	{
		showRectAngle = !showRectAngle;
	}
}

//-----------------------------------------------
//�S�ẴL�����N�^�[�̕`����s��
void CharacterManager::AllDraw()
{
	//�L�����N�^�[�̕`��
	for (auto it : character)
	{
		it->Draw();
	}

	//�����蔻��̉���
	if (showRectAngle)
	{
		database.DrawRectAngle();
	}
}


//����������������������������������������������������������������������������������������������

//-----------------------------------------------
//�S�ẴL�����N�^�[����p�����[�^�����󂯎��
void CharacterManager::GetCharacterParameter()
{
	//�p�����[�^�̃f�[�^�����Z�b�g����
	database.ClearCharacterData();

	//�p�����[�^�����󂯎��
	for (auto it : character)
	{
		database.AddCharacterData(it->GetParameter());
	}
}

//-----------------------------------------------
//�S�ẴL�����N�^�[��Update���Ă�
void CharacterManager::AllCharacterUpdate()
{
	for (auto it : character)
	{
		it->Update(database.GetCharacterData());
	}
}

//-----------------------------------------------
//�e�L�����N�^�[�̍쐬�����L�����N�^�[���󂯎��A�o�^����
void CharacterManager::GetCreatedCharacter()
{
	size_t size = character.size();
	for (size_t i = 0; i < size; ++i)
	{
		auto data = character[i]->GetCreatedCharacter();
		if ((*data).empty())
			continue;

		character.insert(character.end(), (*data).begin(), (*data).end());
	}
}

//-----------------------------------------------
//��Ԃ�Delete�̃L�����N�^�[���폜����
void CharacterManager::KillDeleteCharacter()
{
	auto removeIt = std::remove_if(character.begin(), character.end(), RemoveStateDelete);
	character.erase(removeIt, character.end());

	character.shrink_to_fit();
}

//-----------------------------------------------
//�L�����N�^�[��priority���Ƀ\�[�g����
void CharacterManager::SortCharacter()
{
	std::sort(character.begin(), character.end(), SortAsc);
}



//-----------------------------------------------
//priority(�D��x)�Ń\�[�g�������
bool CharacterManager::SortAsc(const std::shared_ptr<CharacterAbstract>& left,
	const std::shared_ptr<CharacterAbstract>& right)
{
	return (*left->GetParameter().priority) < (*right->GetParameter().priority);
}

//-----------------------------------------------
//�X�e�[�^�X�����āA������Delete�̃L�����N�^�[���폜�������
bool CharacterManager::RemoveStateDelete(const std::shared_ptr<CharacterAbstract>& chara)
{
	return (*chara->GetParameter().state) == State::Delete;
}

