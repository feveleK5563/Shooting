#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "Math.h"


//画像名
enum struct ImageName
{
	BackImage,			//背景
	PlayerImage,		//プレイヤー
	EnemyImage,			//敵
	NomalBulletImage,	//通常弾
	BombEffect,			//爆発エフェクト
};

//画像データ
struct ImageData
{
	int*		handle;		//グラフィックハンドル
	int			sheetNum;	//画像枚数
	Math::Box2D	size;		//画像サイズ
};

//画像読み込みくん
class ImageLoader
{
private:
	std::unordered_map<ImageName, ImageData> imageData;	//画像データ

	ImageLoader() = default;

public:
	~ImageLoader();

	//画像読み込み
	void LoadOneImage(ImageName imgName, const std::string& filePath);
	
	//画像分割読み込み
	void LoadDivImage(ImageName imgName, const std::string& filePath, int allNum, int xNum, int yNum, int xSize, int ySize);

	//画像データの取得
	const ImageData& GetImageData(ImageName imgName);
	
	//画像データの解放
	void DeleteImageData(ImageName imgName);

	//全ての画像データの解放
	void AllDeleteImageData();

	//インスタンスを得る
	static ImageLoader& GetInstance();
};

//-----------------------------------------------------------------------------
namespace Image
{
	static ImageLoader& imageLoader = ImageLoader::GetInstance();
}