#pragma once
#include <memory>
#include "CharacterAbstract.h"
#include "CharacterParameter.h"

class CharacterFactory
{
public:
	//”wŒi‚Ì¶¬
	std::shared_ptr<CharacterAbstract> CreateBack(const ImageData& imageData, const Math::Vec2& moveVec, bool isInfinite);
	//ƒvƒŒƒCƒ„[‚Ì¶¬
	std::shared_ptr<CharacterAbstract> CreatePlayer(const ImageData& imageData, const Math::Vec2& pos);

	//’Êí’e‚Ì¶¬
	std::shared_ptr<CharacterAbstract> CreateNomalBullet(CharacterID ID, CharacterID hitID, ImageData imageData, float angle, float moveVolume, Math::Vec2 pos, int R, int G, int B);
};