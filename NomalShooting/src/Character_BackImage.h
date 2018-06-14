#pragma once
#include <memory>
#include "ImageDrawer.h"
#include "Move.h"
#include "CharacterAbstract.h"
#include "CharacterParameter.h"

class Character_BackImage : public CharacterAbstract
{
private:
	ImageDrawer imageDrawer;
	bool isInfinite;	//無限スクロールするか否か

public:
	//画像データ、移動量、無限スクロールするか否かを設定
	Character_BackImage(const ImageData& imageData, const Math::Vec2& moveVec, bool setIsInfinite);
	void Update(const ROD& data) override;
	void Draw() override;

private:
	void InfiniteScroll();	//無限スクロールさせるための処理
};