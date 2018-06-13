#pragma once
#include "Math.h"

//-----------------------------------------------
//座標と移動量管理くん
class Move
{
private:
	Math::Vec2	pos;		//座標
	Math::Vec2	moveVec;	//移動ベクトル
	float		angle;		//角度
	float		moveVolume;	//移動量

public:
	//コンストラクタ(座標、移動ベクトル、角度、移動量は0)
	Move();
	//コンストラクタ(座標、移動ベクトル、角度、移動量を任意の数値に設定)
	Move(	const Math::Vec2&	pos, 
			const Math::Vec2&	moveVec,
			float				angle,
			float				moveVolume);

	void SetPosX(float posX);				//座標Xを設定
	void SetPosY(float posY);				//座標Yを設定
	void SetAngle(float angle);			//角度を設定
	void SetVolume(float moveVolume);		//移動量を設定

	void ClearMoveVec();									//移動ベクトルをゼロクリアする
	void AddMoveVec(const Math::Vec2& addVec);				//移動ベクトルに指定ベクトル分加算する
	void AddAngle(float addAngle);							//角度に指定量加算する
	void AddMoveVolume(float addVolume);					//移動量に指定量加算する
	void AddAngleMoveVec();									//角度と移動量からベクトルを算出し、移動ベクトルに加算する
	void UpdatePos();										//移動ベクトル量を座標に加算する(動かす)

	const Math::Vec2&	GetPos() const;			//座標を取得する
	const Math::Vec2&	GetMoveVec() const;		//移動ベクトルを取得する
	float				GetAngle() const;		//角度を取得する
	float				GetMoveVolume() const;	//移動量を取得する
};