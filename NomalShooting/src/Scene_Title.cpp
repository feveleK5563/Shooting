#include "DxLib.h"
#include "InputState.h"
#include "System.h"

#include "Scene_Title.h"

Scene_Title::Scene_Title(const SceneParameter& parameter)
{
	Image::imageLoader.LoadOneImage(ImageName::BackImage, "data/image/title.png");
	back.reset(new Character_BackImage(Image::imageLoader.GetImageData(ImageName::BackImage), Math::Vec2(0, 0), false));
}

Scene_Title::~Scene_Title()
{
	Image::imageLoader.AllDeleteImageData();
}

void Scene_Title::Update()
{

}

SceneParameter Scene_Title::GetParameter()
{
	SceneParameter parameter;

	if (Input::key[KEY_INPUT_SPACE] == DOWN)
		parameter.SetParameterData(SceneParamName::NextScene, (int)SceneName::Game);

	return parameter;
}

void Scene_Title::Draw()
{
	back->Draw();
}