#include "Move.h"

//コンストラクタ(座標、移動ベクトルは0)
Move::Move():
	pos(0, 0),
	moveVec(0, 0){}

//コンストラクタ(座標、移動ベクトルを任意の数値に設定)
Move::Move(	const Math::Vec2&	pos,
			const Math::Vec2&	moveVec,
			float				angle,
			float				moveVolume) :
	pos(pos),
	moveVec(moveVec),
	angle(angle),
	moveVolume(moveVolume){}


//座標Xを設定
void Move::SetPosX(float posX)
{
	pos.x = posX;
}
//座標Yを設定
void Move::SetPosY(float posY)
{
	pos.y = posY;
}
//角度を設定
void Move::SetAngle(float angle)
{
	this->angle = angle;
}
//移動量を設定
void Move::SetVolume(float moveVolume)
{
	this->moveVolume = moveVolume;
}


//移動ベクトルをゼロクリアする
void Move::ClearMoveVec()
{
	moveVec = Math::Vec2(0, 0);
}
//移動ベクトルに指定ベクトル分加算する
void Move::AddMoveVec(const Math::Vec2& addVec)
{
	moveVec += addVec;
}
//角度に指定量加算する
void Move::AddAngle(float addAngle)
{
	angle += addAngle;
}
//移動量に指定量加算する
void Move::AddMoveVolume(float addVolume)
{
	moveVolume += addVolume;
}
//角度と移動量からベクトルを算出し、移動ベクトルに加算する
void Move::AddAngleMoveVec()
{
	AddMoveVec(Math::Vec2(
		cosf(angle) * moveVolume,
		sinf(angle) * moveVolume)
	);
}
//移動ベクトル量を座標に加算する(動かす)
void Move::UpdatePos()
{
	pos += moveVec;
}


//座標を取得する
const Math::Vec2& Move::GetPos() const
{
	return pos;
}
//移動ベクトルを取得する
const Math::Vec2& Move::GetMoveVec() const
{
	return moveVec;
}
//角度を取得する
float Move::GetAngle() const
{
	return angle;
}
//移動量を取得する
float Move::GetMoveVolume() const
{
	return moveVolume;
}