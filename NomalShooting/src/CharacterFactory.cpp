#include "Character_BackImage.h"
#include "Character_Player.h"
#include "Character_Bullet.h"

#include "CharacterFactory.h"

//�w�i�̐���
std::shared_ptr<CharacterAbstract> CharacterFactory::CreateBack(const ImageData& imageData, const Math::Vec2& moveVec, bool isInfinite)
{
	return std::make_shared<Character_BackImage>(imageData, moveVec, isInfinite);
}

//�v���C���[�̐���
std::shared_ptr<CharacterAbstract> CharacterFactory::CreatePlayer(const ImageData& imageData, const Math::Vec2& pos)
{
	return std::make_shared<Character_Player>(imageData, pos);
}

//�ʏ�e�̍쐬
std::shared_ptr<CharacterAbstract> CharacterFactory::CreateNomalBullet(CharacterID ID, CharacterID hitID, ImageData imageData, float angle, float moveVolume, Math::Vec2 pos, int R, int G, int B)
{
	return std::make_shared<Character_Bullet>(ID, hitID, imageData, angle, moveVolume, pos, R, G, B);
}
