#pragma once
#include "SceneManager.h"

class Looper
{
private:
	SceneManager Scene;

public:
	Looper();
	~Looper();
	void Loop();
};