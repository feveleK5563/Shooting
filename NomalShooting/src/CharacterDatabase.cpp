#include "DxLib.h"
#include "Math.h"

#include "CharacterDatabase.h"

//データを追加する
void CharacterDatabase::AddCharacterData(const CharacterParameter& parameter)
{
	this->data.emplace_back(std::make_shared<ROCharacterParameter>(parameter));
}

//保持しているデータを全て削除する
void CharacterDatabase::ClearCharacterData()
{
	data.clear();
	data.shrink_to_fit();
}

//データのまとめを返す
const ROD& CharacterDatabase::GetCharacterData()
{
	return data;
}

//データから当たり判定矩形を調べて描画する
void CharacterDatabase::DrawHitBase()
{
	int color = GetColor(255, 255, 255);

	for (const auto& it : data)
	{
		if (it->objParam == nullptr)
			continue;

		Math::Box2D box = (it->objParam->hitBase);

		DrawBox(box.x, box.y, 
				box.x + box.w, box.y + box.h,
				color, false);
	}
}