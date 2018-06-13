#pragma once
#include "SceneParameter.h"

//シーンの抽象クラス
class SceneAbstract
{
public:
	virtual ~SceneAbstract() = default;
	virtual void Update() = 0;
	virtual SceneParameter GetParameter() = 0;
	virtual void Draw() = 0;
};
