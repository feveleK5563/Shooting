#pragma once
#include <vector>
#include "Math.h"
#include "ImageLoader.h"

//色指定
class Color
{
public:
	int r, g, b;
	Color();
	Color(int r, int g, int b);
	Color(const Color& color);
};

//画像データの描画とアニメーションの管理
class ImageDrawer
{
private:
	ImageData	imageData;		//画像データ
	Math::Vec2	criterionPos;	//描画の基準位置
	float		nowAnimImage;	//現在のアニメーション画像
	float		animWaitTime;	//アニメーションの待機時間
	bool		isLoop;			//アニメーションのループフラグ
	Color		color;			//RGB(赤緑青)

public:
	//コンストラクタ(描画したい画像データとループするか否かを指定)
	ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop);
	//コンストラクタ(描画したい画像データとループするか否かと描画輝度を指定)
	ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, bool isLoop, const Color& color);
	//コンストラクタ(描画したい画像データとアニメーションのウェイト時間とループするか否かと描画輝度を指定)
	ImageDrawer(const ImageData& imageData, const Math::Vec2& criterionPos, float animWaitTime, bool isLoop, const Color& color);

	bool Run();	//アニメーションさせる(アニメーションが一周したらtrueが返る)

	void Draw(const Math::Vec2& pos, float scale, float angle, bool isTurn);	//描画する
	void DrawOne(const Math::Vec2& pos, float scale, float angle, bool isTurnint, int imageSheet);	//指定番号の画像を描画する

	const ImageData& GetImageData() const;	//画像データを取得
};