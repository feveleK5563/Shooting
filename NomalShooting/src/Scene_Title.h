#pragma once
#include <memory>
#include "SceneAbstract.h"
#include "SceneParameter.h"
#include "ImageLoader.h"
#include "Character_BackImage.h"

class Scene_Title : public SceneAbstract
{
private:
	std::unique_ptr<Character_BackImage> back;

public:
	Scene_Title(const SceneParameter& parameter);
	~Scene_Title();

	void Update() override;
	SceneParameter GetParameter() override;
	void Draw() override;
};