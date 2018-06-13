#include "SceneParameter.h"

SceneParameter::SceneParameter()
{
	parameter[SceneParamName::NextScene] = (int)SceneName::NoChangeScene;
}

//指定したパラメーターを設定する
void SceneParameter::SetParameterData(SceneParamName key, int data)
{
	parameter[key] = data;
}

//指定したパラメーターを取得する
int SceneParameter::GetParameterData(SceneParamName key)
{
	auto it = parameter.find(key);//指定キーを取得

	if (it == parameter.end()) //無かったらエラー
	{
		return Error;//エラー
	}
	else
	{
		return it->second;//あったら値を返す
	}
}