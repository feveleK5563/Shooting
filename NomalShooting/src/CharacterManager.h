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
	bool showRectAngle;	//当たり判定矩形可視化フラグ

	//キャラクター
	std::vector<std::shared_ptr<CharacterAbstract>> character;
	//キャラクターのパラメーターを受け取り、各キャラクターに参照させる
	CharacterDatabase database;

public:
	CharacterManager();
	void AddCharacter(const std::shared_ptr<CharacterAbstract>& set);	//引数に指定したオブジェクトを追加する
	void AllUpdate();		//全てのキャラクターの更新を行う
	void AllDraw();			//全てのキャラクターの描画を行う

private:
	void GetCharacterParameter();	//全てのキャラクターからパラメータ情報を受け取る
	void AllCharacterUpdate();		//全てのキャラクターのUpdateを呼ぶ
	void GetCreatedCharacter();		//キャラクターの作成したキャラクターを受け取り、登録する
	void KillDeleteCharacter();		//状態がDeleteのキャラクターを削除する
	void SortCharacter();			//キャラクターをpriority順にソートする

	//priority(優先度)でソートする条件
	static bool SortAsc(const std::shared_ptr<CharacterAbstract>& left,
		const std::shared_ptr<CharacterAbstract>& right);

	//ステータスを見て状態がDeleteのキャラクターを削除する条件
	static bool RemoveStateDelete(const std::shared_ptr<CharacterAbstract>& chara);
};