#pragma once
#include <vector>
#include <memory>
#include "CharacterParameter.h"
typedef std::vector<std::unique_ptr<ROCharacterParameter>> ROD; //ReadOnlyData

//キャラクターからパラメーターを受け取り、
//他のキャラクターにそのパラメーターを参照させる
class CharacterDatabase
{
private:
	std::vector<std::unique_ptr<ROCharacterParameter>> data;

public:
	void AddCharacterData(const CharacterParameter& parameter);	//データを追加する
	void ClearCharacterData();	//保持しているデータを全て削除する
	const ROD& GetCharacterData();	//データのまとめを返す
	void DrawRectAngle();	//データから矩形を調べて描画する
};