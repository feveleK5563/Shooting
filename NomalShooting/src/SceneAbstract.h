#pragma once
#include "SceneParameter.h"

//�V�[���̒��ۃN���X
class SceneAbstract
{
public:
	virtual ~SceneAbstract() = default;
	virtual void Update() = 0;
	virtual SceneParameter GetParameter() = 0;
	virtual void Draw() = 0;
};
