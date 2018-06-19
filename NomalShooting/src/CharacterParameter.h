#pragma once
#include "Math.h"
#include "Move.h"
#include "ImageDrawer.h"
#include "System.h"
#include "TimeCounter.h"

//身元
enum struct CharacterID
{
	Non				= 0,		//未設定
	BackGround		= 1 << 0,	//背景
	Player			= 1 << 1,	//プレイヤー
	EnemyCreator	= 1 << 2,	//敵生成器
	Enemy			= 1 << 3,	//敵
	PlayerBullet	= 1 << 4,	//プレイヤー弾
	EnemyBullet		= 1 << 5,	//敵弾
	UI				= 1 << 6,	//UI
	Effect			= 1 << 7,	//エフェクト
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

//オブジェクト(プレイヤーとか敵とかを指す)に使用するパラメーター
class ObjectParameter
{
public:
	int			life;		//体力
	Move		move;		//座標と動作
	Math::Box2D	hitBase;	//当たり判定

	ObjectParameter();
};

//パラメーター構造体
struct CharacterParameter
{
	std::shared_ptr<CharacterID>		ID;				//身元(必須)
	std::shared_ptr<float>				priority;		//優先度(必須)
	std::shared_ptr<unsigned int>		createdNum;		//生成したキャラクターの数(必須)
	std::shared_ptr<State>				state;			//状態
	std::shared_ptr<TimeCounter>		timeCnt;		//時間計測
	std::shared_ptr<ObjectParameter>	objParam;		//個体が使用するパラメーター

	CharacterParameter(CharacterID ID, float priority, State state);
	void UseObjectParameter();
};

//読み取り専用パラメーター構造体
struct ROCharacterParameter
{
	const std::shared_ptr<const CharacterID>		ID;				//身元(必須)
	const std::shared_ptr<const float>				priority;		//優先度(必須)
	const std::shared_ptr<const unsigned int>		createdNum;		//生成したキャラクターの数(必須)
	const std::shared_ptr<const State>				state;			//状態
	const std::shared_ptr<const ObjectParameter>	objParam;		//個体が使用するパラメーター

	ROCharacterParameter(const CharacterParameter& character);
};