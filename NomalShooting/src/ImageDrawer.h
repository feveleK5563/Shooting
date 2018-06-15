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
	int			R, G, B;		//描画輝度(デフォルトで255,255,255)

public:
	//コンストラクタ(描画したい画像データとループするか否かを指定)
	ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop);
	//コンストラクタ(描画したい画像データとループするか否かと描画輝度を指定)
	ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop, int R, int G, int B);

	void Run();	//アニメーションさせる(不要なら呼ばなくてもよい)

	void Draw(const Math::Vec2& pos, float scale, float angle, bool isTurn);	//描画する
	void DrawOne(const Math::Vec2& pos, float scale, float angle, bool isTurnint, int imageSheet);	//指定番号の画像を描画する

	const ImageData& GetImageData() const;	//画像データを取得
};