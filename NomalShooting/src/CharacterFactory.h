#pragma once
#include <memory>
#include "CharacterAbstract.h"
#include "CharacterParameter.h"
#include "Behavior.h"

class CharacterFactory
{
public:
	//敵生成器の生成
	std::shared_ptr<CharacterAbstract> CreateEnemyCreator();
	
	//背景の生成
	std::shared_ptr<CharacterAbstract> CreateBack(
		const ImageData&	imageData,
		const Math::Vec2&	moveVec,
		bool				isInfinite);
	
	//プレイヤーの生成
	std::shared_ptr<CharacterAbstract> CreatePlayer(
		const ImageData&	imageData,
		const Math::Vec2&	pos);

	//敵の生成
	std::shared_ptr<CharacterAbstract> CreateEnemy(
		int					life,
		Behavior			motion,
		const ImageData&	imageData,
		const Math::Vec2&	pos,
		const Color&		color);
	
	//通常弾の生成
	std::shared_ptr<CharacterAbstract> CreateNomalBullet(
		CharacterID			ID,
		Behavior			moveBehavior,
		int					hitTargetID,
		const ImageData&	imageData,
		float				angle,
		float				moveVolume,
		Math::Vec2			pos,
		const Color&		color);

	//エフェクトの生成
	std::shared_ptr<CharacterAbstract> CreateEffect(
		const ImageData&	imageData,
		const Math::Vec2&	pos
	);
};