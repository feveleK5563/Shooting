#include "Math.h"

#include "Looper.h"

Looper::Looper() :
	Scene(SceneName::Title) {}

Looper::~Looper() {}

void Looper::Loop()
{
	Scene.Update();
	Scene.Draw();
}