#include <algorithm>

#include "CharacterManager.h"

//priority(優先度)でソートする
bool CharacterManager::SortAsc(	const std::shared_ptr<CharacterAbstract>& left, 
								const std::shared_ptr<CharacterAbstract>& right)
{
	return (*left->GetParameter().priority) < (*right->GetParameter().priority);
}

//ステータスを見て、条件がDeleteのキャラクターを削除する条件
bool CharacterManager::RemoveStateDelete(const std::shared_ptr<CharacterAbstract>& chara)
{
	return (*chara->GetParameter().state) == State::Delete;
}


//引数に指定したオブジェクトを登録する
void CharacterManager::SetCharacter(const std::shared_ptr<CharacterAbstract>& set)
{
	character.emplace_back(set);
}

//キャラクターをpriority順にソートする
void CharacterManager::SortCharacter()
{
	std::sort(character.begin(), character.end(), SortAsc);
}

//全てのキャラクターの更新を行う
void CharacterManager::AllUpdate()
{
	//パラメータのデータをリセットする
	database.ClearCharacterData();

	//全てのキャラクターからパラメータ情報を受け取る
	for (auto it : character)
	{
		database.AddCharacterData(it->GetParameter());
	}

	//各キャラクターを更新する
	for (auto it : character)
	{
		it->Update(database.GetCharacterData());
	}

	//各キャラクターの作成したデータを登録する
	size_t size = character.size();
	for (size_t i = 0; i < size; ++i)
	{
		auto data = character[i]->GetCreatedCharacter();
		if ((*data).empty())
			continue;

		character.insert(character.end(), (*data).begin(), (*data).end());
	}

	//状態がDeathのキャラクターを一括削除する
	auto removeIt = std::remove_if(character.begin(), character.end(), RemoveStateDelete);
	character.erase(removeIt, character.end());

	character.shrink_to_fit();
}

//全てのキャラクターの描画を行う
void CharacterManager::AllDraw()
{
	for (auto it : character)
	{
		it->Draw();
	}

	database.DrawRectAngle();
}