#include "Character_BackImage.h"
#include "Character_Player.h"
#include "Character_NomalBullet.h"

#include "CharacterFactory.h"

//”wŒi‚Ì¶¬
std::shared_ptr<CharacterAbstract> CharacterFactory::CreateBack(const ImageData& imageData, const Math::Vec2& moveVec, bool isInfinite)
{
	return std::make_shared<Character_BackImage>(imageData, moveVec, isInfinite);
}

//ƒvƒŒƒCƒ„[‚Ì¶¬
std::shared_ptr<CharacterAbstract> CharacterFactory::CreatePlayer(const ImageData& imageData, const Math::Vec2& pos)
{
	return std::make_shared<Character_Player>(imageData, pos);
}

//’Êí’e‚Ìì¬
std::shared_ptr<CharacterAbstract> CharacterFactory::CreateNomalBullet(CharacterID ID, ImageData imageData, float angle, float moveVolume, Math::Vec2 pos)
{
	return std::make_shared<Character_NomalBullet>(ID, imageData, angle, moveVolume, pos);
}
