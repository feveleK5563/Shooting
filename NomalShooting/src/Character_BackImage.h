#pragma once
#include <memory>
#include "ImageDrawer.h"
#include "Move.h"
#include "CharacterAbstract.h"
#include "CharacterParameter.h"

class Character_BackImage : public CharacterAbstract
{
private:
	ImageDrawer imageDrawer;
	bool isInfinite;	//�����X�N���[�����邩�ۂ�

public:
	//�摜�f�[�^�A�ړ��ʁA�����X�N���[�����邩�ۂ���ݒ�
	Character_BackImage(const ImageData& imageData, const Math::Vec2& moveVec, bool setIsInfinite);
	void Update(const ROD& data) override;
	void Draw() override;

private:
	void InfiniteScroll();	//�����X�N���[�������邽�߂̏���
};