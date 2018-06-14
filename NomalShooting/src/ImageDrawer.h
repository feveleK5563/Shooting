#pragma once
#include <vector>
#include "Math.h"
#include "ImageLoader.h"

class ImageDrawer
{
private:
	ImageData	imageData;		//画像データ
	Math::Vec2	criterionPos;	//描画の基準位置
	float		nowAnimImage;	//現在のアニメーション画像
	float		animWaitTime;	//アニメーションの待機時間
	bool		isLoop;			//アニメーションのループフラグ

public:
	//コンストラクタ(描画したい画像データとループするか否かを指定)
	ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop);

	void Run();	//アニメーションさせる(不要なら呼ばなくてもよい)

	void Draw(const Math::Vec2& pos, float scale, float angle, bool isTurn);	//描画する
	void DrawOne(const Math::Vec2& pos, float scale, float angle, bool isTurnint, int imageSheet);	//一枚だけ描画する

	const ImageData& GetImageData() const;	//画像データを取得
};