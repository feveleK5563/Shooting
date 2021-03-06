#include "Character_EnemyCreator.h"
#include "Character_BackImage.h"
#include "Character_Player.h"
#include "Character_Enemy.h"
#include "Character_Bullet.h"
#include "Character_Effect.h"

#include "CharacterFactory.h"

//-----------------------------------------------
//敵生成器の生成
std::shared_ptr<CharacterAbstract> CharacterFactory::CreateEnemyCreator()
{
	return std::make_shared<Character_EnemyCreator>(0.0f);
}

//-----------------------------------------------
//背景の生成
std::shared_ptr<CharacterAbstract> CharacterFactory::CreateBack(
	const ImageData&	imageData,
	const Math::Vec2&	moveVec,
	bool				isInfinite)
{
	return std::make_shared<Character_BackImage>(1.0f, imageData, moveVec, isInfinite);
}

//-----------------------------------------------
//プレイヤーの生成
std::shared_ptr<CharacterAbstract> CharacterFactory::CreatePlayer(
	const ImageData&	imageData,
	const Math::Vec2&	pos)
{
	return std::make_shared<Character_Player>(1.1f, imageData, pos);
}

//-----------------------------------------------
//敵の生成
std::shared_ptr<CharacterAbstract> CharacterFactory::CreateEnemy(
	int					life,
	Behavior			motion,
	const ImageData&	imageData,
	const Math::Vec2&	pos,
	const Color&		color)
{
	return std::make_shared<Character_Enemy>(1.2f, life, motion, imageData, pos, color);
}

//-----------------------------------------------
//通常弾の作成
std::shared_ptr<CharacterAbstract> CharacterFactory::CreateNomalBullet(
	CharacterID			ID,
	Behavior			moveBehavior, 
	int					hitTargetID,
	const ImageData&	imageData,
	float				angle,
	float				moveVolume,
	Math::Vec2			pos,
	const Color&		color)
{
	return std::make_shared<Character_Bullet>(1.3f, ID, moveBehavior, hitTargetID, imageData, angle, moveVolume, pos, color);
}

//-----------------------------------------------
//エフェクトの作成
std::shared_ptr<CharacterAbstract> CharacterFactory::CreateEffect(
	const ImageData&	imageData,
	const Math::Vec2&	pos)
{
	return std::make_shared<Character_Effect>(1.4f, imageData, pos);
}