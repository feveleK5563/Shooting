#pragma once
#include <memory>
#include "CharacterAbstract.h"
#include "CharacterParameter.h"
#include "Behavior.h"

class CharacterFactory
{
public:
	//�G������̐���
	std::shared_ptr<CharacterAbstract> CreateEnemyCreator();
	
	//�w�i�̐���
	std::shared_ptr<CharacterAbstract> CreateBack(
		const ImageData&	imageData,
		const Math::Vec2&	moveVec,
		bool				isInfinite);
	
	//�v���C���[�̐���
	std::shared_ptr<CharacterAbstract> CreatePlayer(
		const ImageData&	imageData,
		const Math::Vec2&	pos);

	//�G�̐���
	std::shared_ptr<CharacterAbstract> CreateEnemy(
		int					life,
		Behavior			motion,
		const ImageData&	imageData,
		const Math::Vec2&	pos,
		const Color&		color);
	
	//�ʏ�e�̐���
	std::shared_ptr<CharacterAbstract> CreateNomalBullet(
		CharacterID			ID,
		Behavior			moveBehavior,
		int					hitTargetID,
		const ImageData&	imageData,
		float				angle,
		float				moveVolume,
		Math::Vec2			pos,
		const Color&		color);

	//�G�t�F�N�g�̐���
	std::shared_ptr<CharacterAbstract> CreateEffect(
		const ImageData&	imageData,
		const Math::Vec2&	pos
	);
};