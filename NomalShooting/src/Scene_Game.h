#pragma once
#include <memory>
#include "SceneAbstract.h"
#include "SceneParameter.h"
#include "ImageLoader.h"
#include "CharacterFactory.h"
#include "CharacterManager.h"

class Scene_Game : public SceneAbstract
{
private:
	CharacterManager charaManager;
	CharacterFactory charaFactory;

public:
	Scene_Game(const SceneParameter& parameter);
	~Scene_Game();

	void Update();
	SceneParameter GetParameter();
	void Draw();
};