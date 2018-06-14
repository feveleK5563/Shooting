#pragma once
#include "CharacterAbstract.h"
typedef bool(*Behavior)(CharacterAbstract&);

namespace BF
{
	//画面外に出たら自身を削除する
	bool WindowOutDelete(CharacterAbstract& chara);

	//ジョイパッドで操作する
	bool ControllJpad(CharacterAbstract& chara);

	//プレイヤー用通常弾を生成する
	bool CreateNomalBulletForPlayer(CharacterAbstract& chara);
}