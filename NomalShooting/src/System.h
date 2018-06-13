#pragma once
#include "Math.h"

class System
{
public:
	static const int windowSizeX;	//�E�B���h�E�T�C�YX
	static const int windowSizeY;	//�E�B���h�E�T�C�YY

	//��ʊO����(�����ɋ�`���w��A��ʊO�ɏo�Ă�����true)
	static bool WindowOutBox(const Math::Box2D& hitBase);

	//���S��delete����
	template<class T> static void SafeDelete(T& t);
	//���S��delete����(�z���)
	template<class T> static void SafeDeleteArr(T& t);
};