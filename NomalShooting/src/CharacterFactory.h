#pragma once
#include <memory>
#include "CharacterAbstract.h"
#include "CharacterParameter.h"

class CharacterFactory
{
public:
	//背景の生成
	std::shared_ptr<CharacterAbstract> CreateBack(const ImageData& imageData, const Math::Vec2& moveVec, bool isInfinite);
	//プレイヤーの生成
	std::shared_ptr<CharacterAbstract> CreatePlayer(const ImageData& imageData, const Math::Vec2& pos);

	//通常弾の生成
	std::shared_ptr<CharacterAbstract> CreateNomalBullet(CharacterID ID, ImageData imageData, float angle, float moveVolume, Math::Vec2 pos);
};