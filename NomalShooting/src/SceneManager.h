#pragma once
#include <memory>
#include "SceneAbstract.h"

//シーン管理
class SceneManager
{
private:
	std::unique_ptr<SceneAbstract> Scene;

public:
	//コンストラクタ(最初に設定するシーンを引数に入れる)
	SceneManager(SceneName SceneName);

private:
	//指定したシーンに変更
	void SetScene(SceneParameter parameter);

public:
	//シーンのアップデート処理
	void Update();

	//シーンの描画処理
	void Draw();
};