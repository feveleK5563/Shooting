#include "DxLib.h"
#include "InputState.h"
#include "System.h"

#include "Scene_Game.h"

Scene_Game::Scene_Game(const SceneParameter& parameter)
{
	Image::imageLoader.LoadOneImage(ImageName::BackImage, "data/image/backStars.png");
	Image::imageLoader.LoadOneImage(ImageName::PlayerImage, "data/image/fighter.png");
	Image::imageLoader.LoadOneImage(ImageName::NomalBulletImage, "data/image/bullet.png");
	Image::imageLoader.LoadOneImage(ImageName::EnemyImage, "data/image/enemy.png");

	charaManager.AddCharacter(
		charaFactory.CreateEnemyCreator()
	);

	charaManager.AddCharacter(
		charaFactory.CreateBack(
			Image::imageLoader.GetImageData(ImageName::BackImage),
			Math::Vec2(-5, 0),
			true
		)
	);

	charaManager.AddCharacter(
		charaFactory.CreatePlayer(
			Image::imageLoader.GetImageData(ImageName::PlayerImage),
			Math::Vec2(100, (float)System::windowSizeY / 2)
		)
	);

	/*for (int i = 0; i < 300; ++i)
	{
		charaManager.AddCharacter(
			charaFactory.CreateEnemy(
				Image::imageLoader.GetImageData(ImageName::EnemyImage),
				Math::Vec2(float(rand() % System::windowSizeX), float(rand() % System::windowSizeY))
			)
		);
	}*/
}

Scene_Game::~Scene_Game()
{
	Image::imageLoader.AllDeleteImageData();
}

void Scene_Game::Update()
{
	charaManager.AllUpdate();
}

SceneParameter Scene_Game::GetParameter()
{
	SceneParameter parameter;

	if (Input::key[KEY_INPUT_SPACE] == DOWN)
		parameter.SetParameterData(SceneParamName::NextScene, (int)SceneName::Title);

	return parameter;
}

void Scene_Game::Draw()
{
	charaManager.AllDraw();
}