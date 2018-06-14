#pragma once
#include "CharacterDatabase.h"
#include "CharacterAbstract.h"
typedef bool(*Behavior)(CharacterAbstract&, const ROD&);

namespace BF
{
	//画面外に出たら自身を削除する
	bool WindowOutDelete(CharacterAbstract& chara, const ROD& data);

	//シンプルに移動させる
	bool NomalMove(CharacterAbstract& chara, const ROD& data);

	//ジョイパッドで操作する
	bool ControllJpad(CharacterAbstract& chara, const ROD& data);

	//プレイヤー用通常弾を生成する
	bool CreateNomalBulletForPlayer(CharacterAbstract& chara, const ROD& data);
}