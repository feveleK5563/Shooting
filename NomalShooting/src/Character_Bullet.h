#pragma once
#include "ImageDrawer.h"
#include "Behavior.h"
#include "CharacterAbstract.h"

class Character_Bullet : public CharacterAbstract
{
private:
	ImageDrawer	imageDrawer;
	Behavior	moveBehavior;
	int			hitTargetID;

public:
	Character_Bullet(	float			priority,		//優先度
						CharacterID		ID,				//自身のID
						Behavior		moveBehavior,	//動作の振る舞い関数
						int				hitTargetID,	//接触判定用のID
						ImageData		imageData,		//画像データ
						float			angle,			//傾き
						float			moveVolume,		//移動量
						Math::Vec2		pos,			//出現座標
						const Color&	color);			//色

	void Update(const ROD& data) override;
	void Draw() override;
};