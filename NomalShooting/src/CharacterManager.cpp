#include <algorithm>
#include "DxLib.h"
#include "InputState.h"

#include "CharacterManager.h"

CharacterManager::CharacterManager() :
	showRectAngle(false) {}

//-----------------------------------------------
//引数に指定したオブジェクトを登録する
void CharacterManager::AddCharacter(const std::shared_ptr<CharacterAbstract>& set)
{
	character.emplace_back(set);
}

//-----------------------------------------------
//全てのキャラクターの更新を行う
void CharacterManager::AllUpdate()
{
	//全てのキャラクターからパラメータ情報を受け取る
	GetCharacterParameter();

	//全てのキャラクターのUpdateを呼ぶ
	AllCharacterUpdate();

	//各キャラクターの作成したデータを受け取り、登録する
	GetCreatedCharacter();

	//状態がDeathのキャラクターを一括削除する
	KillDeleteCharacter();

	//priorityを参照して昇順にソートする
	SortCharacter();

	//左のコントロールキーを押したら当たり判定を可視化させる
	if (Input::key[KEY_INPUT_LCONTROL] == DOWN)
	{
		showRectAngle = !showRectAngle;
	}
}

//-----------------------------------------------
//全てのキャラクターの描画を行う
void CharacterManager::AllDraw()
{
	//キャラクターの描画
	for (auto it : character)
	{
		it->Draw();
	}

	//当たり判定の可視化
	if (showRectAngle)
	{
		database.DrawRectAngle();
	}
}


//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

//-----------------------------------------------
//全てのキャラクターからパラメータ情報を受け取る
void CharacterManager::GetCharacterParameter()
{
	//パラメータのデータをリセットする
	database.ClearCharacterData();

	//パラメータ情報を受け取る
	for (auto it : character)
	{
		database.AddCharacterData(it->GetParameter());
	}
}

//-----------------------------------------------
//全てのキャラクターのUpdateを呼ぶ
void CharacterManager::AllCharacterUpdate()
{
	for (auto it : character)
	{
		it->Update(database.GetCharacterData());
	}
}

//-----------------------------------------------
//各キャラクターの作成したキャラクターを受け取り、登録する
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
//状態がDeleteのキャラクターを削除する
void CharacterManager::KillDeleteCharacter()
{
	auto removeIt = std::remove_if(character.begin(), character.end(), RemoveStateDelete);
	character.erase(removeIt, character.end());

	character.shrink_to_fit();
}

//-----------------------------------------------
//キャラクターをpriority順にソートする
void CharacterManager::SortCharacter()
{
	std::sort(character.begin(), character.end(), SortAsc);
}



//-----------------------------------------------
//priority(優先度)でソートする条件
bool CharacterManager::SortAsc(const std::shared_ptr<CharacterAbstract>& left,
	const std::shared_ptr<CharacterAbstract>& right)
{
	return (*left->GetParameter().priority) < (*right->GetParameter().priority);
}

//-----------------------------------------------
//ステータスを見て、条件がDeleteのキャラクターを削除する条件
bool CharacterManager::RemoveStateDelete(const std::shared_ptr<CharacterAbstract>& chara)
{
	return (*chara->GetParameter().state) == State::Delete;
}

