#pragma once
#include "CharacterDatabase.h"
#include "CharacterAbstract.h"
typedef bool(*Behavior)(CharacterAbstract&);

//振る舞い関数
namespace BF
{
	//画面外に出たら自身を削除する
	bool WindowOutDelete(CharacterAbstract& chara);

	//シンプルに移動させる
	bool NomalMove(CharacterAbstract& chara);

	//ジョイパッドで操作する
	bool ControllJpad(CharacterAbstract& chara);

	//プレイヤー用通常弾を生成する
	bool CreateNomalBulletForPlayer(CharacterAbstract& chara);

	//y軸方向にふわふわしながら移動する
	bool MoveFuwaFuwa(CharacterAbstract& chara);
}

//判定関数
namespace HC
{
	bool HitCheckCharacter(int characterID, CharacterAbstract& chara, const ROD& data);
}