#pragma once
#include "Move.h"
#include "ImageDrawer.h"
#include "System.h"

//身元
enum struct CharacterID
{
	BackGround,		//背景
	Player,			//プレイヤー
	Enemy,			//敵
	PlayerBullet,	//プレイヤー弾
	EnemyBullet,	//敵弾
	UI,				//UI
};

//状態
enum struct State
{
	Non,		//存在なし
	Ready,		//準備
	Active,		//生存
	Death,		//死亡
	Delete,		//削除
};

//パラメーター構造体(使用する値の実体を生成してから使用する)
struct CharacterParameter
{
	std::shared_ptr<CharacterID>	ID;				//身元(必須)
	std::shared_ptr<float>			priority;		//優先度(必須)
	std::shared_ptr<State>			state;			//状態
	std::shared_ptr<Move>			move;			//座標と動作
	std::shared_ptr<Math::Box2D>	hitBase;		//当たり判定

	CharacterParameter(CharacterID ID, float priority);

	void UseState(const State& state);
	void UseMove(const Math::Vec2&	pos, const Math::Vec2&	moveVec, float angle, float moveVolume);
	void UseHitBase(int x, int y, int w, int h);
};

//読み取り専用パラメーター構造体
struct ROCharacterParameter
{
	const std::shared_ptr<const CharacterID>	ID;				//身元(必須)
	const std::shared_ptr<const float>			priority;		//優先度(必須)
	const std::shared_ptr<const State>			state;			//状態
	const std::shared_ptr<const Move>			move;			//座標と動作
	const std::shared_ptr<const Math::Box2D>	hitBase;		//当たり判定

	ROCharacterParameter(const CharacterParameter& character);
};