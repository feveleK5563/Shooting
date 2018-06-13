#include "System.h"

const int System::windowSizeX = 1280;	//�E�B���h�E�T�C�YX
const int System::windowSizeY = 720;	//�E�B���h�E�T�C�YY

//��ʊO����(�����ɉ摜�T�C�Y���w��A��ʊO�ɏo�Ă�����true)
bool System::WindowOutBox(const Math::Box2D& hitBase)
{
	Math::Box2D windowBox(0, 0, windowSizeX, windowSizeY);
	return !windowBox.Hit(hitBase);
}

//���S��delete����
template<class T>void System::SafeDelete(T& t)
{
	if (t != nullptr)
	{
		delete t;
		t = nullptr;
	}
}

//���S��delete����(�z���)
template<class T>void System::SafeDeleteArr(T& t)
{
	if (t != nullptr)
	{
		delete[] t;
		t = nullptr;
	}
}