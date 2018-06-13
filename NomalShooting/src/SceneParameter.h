#pragma once
#include <unordered_map>

//取得できる情報の名前
enum struct SceneParamName
{
	NextScene,
};

//シーン名
enum struct SceneName
{
	NoChangeScene,
	Title,
	Game,
};

//int型限定のシーンパラメーター所有者
class SceneParameter
{
public:
	const static int Error = -1;

private:
	std::unordered_map<SceneParamName, int> parameter;

public:
	SceneParameter();
	void SetParameterData(SceneParamName key, int data);	//指定したパラメーターを設定する
	int GetParameterData(SceneParamName key);			//指定したパラメーターを取得する
};