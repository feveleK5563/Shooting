#pragma once
#include <memory>
#include "CharacterAbstract.h"
#include "CharacterParameter.h"

class CharacterFactory
{
public:
	//�w�i�̐���
	std::shared_ptr<CharacterAbstract> CreateBack(const ImageData& imageData, const Math::Vec2& moveVec, bool isInfinite);
	//�v���C���[�̐���
	std::shared_ptr<CharacterAbstract> CreatePlayer(const ImageData& imageData, const Math::Vec2& pos);

	//�ʏ�e�̐���
	std::shared_ptr<CharacterAbstract> CreateNomalBullet(CharacterID ID, CharacterID hitID, ImageData imageData, float angle, float moveVolume, Math::Vec2 pos, int R, int G, int B);
};