#pragma once
#include <vector>
#include <memory>
#include "CharacterParameter.h"

//キャラクターからパラメーターを受け取り、
//他のキャラクターにそのパラメーターを分配する
class CharacterDatabase
{
private:
	std::vector<std::unique_ptr<ROCharacterParameter>> data;

public:
	void AddCharacterData(const CharacterParameter& parameter);	//データを追加する
	void ClearCharacterData();	//保持しているデータを全て削除する
	const std::vector<std::unique_ptr<ROCharacterParameter>>& GetCharacterData();	//データのまとめを返す
	void DrawRectAngle();	//データから矩形を調べて描画する
};