#pragma once
#include <memory>
#include <vector>
#include "CharacterParameter.h"
#include "CharacterAbstract.h"
#include "CharacterDatabase.h"

//外部で生成されたキャラクターを登録し、管理する
class CharacterManager
{
private:
	//キャラクター
	std::vector<std::shared_ptr<CharacterAbstract>> character;
	//キャラクターのパラメーターを受け取り、各キャラクターに参照させる
	CharacterDatabase database;

	//priority(優先度)でソートする条件
	static bool SortAsc(const std::shared_ptr<CharacterAbstract>& left, 
						const std::shared_ptr<CharacterAbstract>& right);

	//ステータスを見て、状態がDeleteのキャラクターを削除する条件
	static bool RemoveStateDelete(const std::shared_ptr<CharacterAbstract>& chara);

public:
	void SetCharacter(const std::shared_ptr<CharacterAbstract>& set);	//引数に指定したオブジェクトを登録する
	void SortCharacter();	//キャラクターをpriority順にソートする
	void AllUpdate();		//全てのキャラクターの更新を行う
	void AllDraw();			//全てのキャラクターの描画を行う
};