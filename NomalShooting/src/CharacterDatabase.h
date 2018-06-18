#pragma once
#include <vector>
#include <memory>
#include "CharacterParameter.h"
typedef std::vector<std::shared_ptr<ROCharacterParameter>> ROD; //ReadOnlyData

//キャラクターからパラメーターを受け取り、
//他のキャラクターにそのパラメーターを参照させる
class CharacterDatabase
{
private:
	ROD data;

public:
	void AddCharacterData(const CharacterParameter& parameter);	//データを追加する
	void ClearCharacterData();	//保持しているデータを全て削除する
	const ROD& GetCharacterData();	//データのまとめを返す
	void DrawHitBase();	//データから当たり判定矩形を調べて描画する
};