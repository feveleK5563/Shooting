#include <algorithm>

#include "CharacterManager.h"

//priority(�D��x)�Ń\�[�g����
bool CharacterManager::SortAsc(	const std::shared_ptr<CharacterAbstract>& left, 
								const std::shared_ptr<CharacterAbstract>& right)
{
	return (*left->GetParameter().priority) < (*right->GetParameter().priority);
}

//�X�e�[�^�X�����āA������Delete�̃L�����N�^�[���폜�������
bool CharacterManager::RemoveStateDelete(const std::shared_ptr<CharacterAbstract>& chara)
{
	return (*chara->GetParameter().state) == State::Delete;
}


//�����Ɏw�肵���I�u�W�F�N�g��o�^����
void CharacterManager::SetCharacter(const std::shared_ptr<CharacterAbstract>& set)
{
	character.emplace_back(set);
}

//�L�����N�^�[��priority���Ƀ\�[�g����
void CharacterManager::SortCharacter()
{
	std::sort(character.begin(), character.end(), SortAsc);
}

//�S�ẴL�����N�^�[�̍X�V���s��
void CharacterManager::AllUpdate()
{
	//�p�����[�^�̃f�[�^�����Z�b�g����
	database.ClearCharacterData();

	//�S�ẴL�����N�^�[����p�����[�^�����󂯎��
	for (auto it : character)
	{
		database.AddCharacterData(it->GetParameter());
	}

	//�e�L�����N�^�[���X�V����
	for (auto it : character)
	{
		it->Update(database.GetCharacterData());
	}

	//�e�L�����N�^�[�̍쐬�����f�[�^��o�^����
	size_t size = character.size();
	for (size_t i = 0; i < size; ++i)
	{
		auto data = character[i]->GetCreatedCharacter();
		if ((*data).empty())
			continue;

		character.insert(character.end(), (*data).begin(), (*data).end());
	}

	//��Ԃ�Death�̃L�����N�^�[���ꊇ�폜����
	auto removeIt = std::remove_if(character.begin(), character.end(), RemoveStateDelete);
	character.erase(removeIt, character.end());

	character.shrink_to_fit();
}

//�S�ẴL�����N�^�[�̕`����s��
void CharacterManager::AllDraw()
{
	for (auto it : character)
	{
		it->Draw();
	}

	database.DrawRectAngle();
}