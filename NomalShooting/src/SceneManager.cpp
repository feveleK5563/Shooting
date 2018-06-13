#include "Scene_Title.h"
#include "Scene_Game.h"

#include "SceneManager.h"


//コンストラクタ(最初に設定するシーンを引数に入れる)
SceneManager::SceneManager(SceneName SceneName)
{
	SceneParameter parameter;
	parameter.SetParameterData(SceneParamName::NextScene, (int)SceneName);
	SetScene(parameter);
}

//指定したシーンに変更
void SceneManager::SetScene(SceneParameter parameter)
{
	//受け取ったパラメーターから次のシーンを取得
	SceneName nextScene = SceneName(parameter.GetParameterData(SceneParamName::NextScene));

	//次のシーンがNoChangeSceneだったら無効
	if (nextScene == SceneName::NoChangeScene) return;

	Scene.reset();
	switch (nextScene)
	{
	case SceneName::Title:
		Scene = std::make_unique<Scene_Title>(parameter);
		break;

	case SceneName::Game:
		Scene = std::make_unique<Scene_Game>(parameter);
		break;

	default:
		//エラー！！
		break;
	}
}

//シーンのアップデート処理
void SceneManager::Update()
{
	Scene->Update();
	SetScene(Scene->GetParameter());
}

//シーンの描画処理
void SceneManager::Draw()
{
	Scene->Draw();
}