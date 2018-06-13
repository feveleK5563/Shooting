#include "System.h"

const int System::windowSizeX = 1280;	//ウィンドウサイズX
const int System::windowSizeY = 720;	//ウィンドウサイズY

//画面外判定(引数に画像サイズを指定、画面外に出ていたらtrue)
bool System::WindowOutBox(const Math::Box2D& hitBase)
{
	Math::Box2D windowBox(0, 0, windowSizeX, windowSizeY);
	return !windowBox.Hit(hitBase);
}

//安全にdeleteする
template<class T>void System::SafeDelete(T& t)
{
	if (t != nullptr)
	{
		delete t;
		t = nullptr;
	}
}

//安全にdeleteする(配列版)
template<class T>void System::SafeDeleteArr(T& t)
{
	if (t != nullptr)
	{
		delete[] t;
		t = nullptr;
	}
}