#pragma once
#include "Math.h"

//-----------------------------------------------
//���W�ƈړ��ʊǗ�����
class Move
{
private:
	Math::Vec2	pos;		//���W
	Math::Vec2	moveVec;	//�ړ��x�N�g��
	float		angle;		//�p�x
	float		moveVolume;	//�ړ���

public:
	//�R���X�g���N�^(���W�A�ړ��x�N�g���A�p�x�A�ړ��ʂ�0)
	Move();
	//�R���X�g���N�^(���W�A�ړ��x�N�g���A�p�x�A�ړ��ʂ�C�ӂ̐��l�ɐݒ�)
	Move(	const Math::Vec2&	pos, 
			const Math::Vec2&	moveVec,
			float				angle,
			float				moveVolume);

	void SetPosX(float posX);				//���WX��ݒ�
	void SetPosY(float posY);				//���WY��ݒ�
	void SetAngle(float angle);			//�p�x��ݒ�
	void SetVolume(float moveVolume);		//�ړ��ʂ�ݒ�

	void ClearMoveVec();									//�ړ��x�N�g�����[���N���A����
	void AddMoveVec(const Math::Vec2& addVec);				//�ړ��x�N�g���Ɏw��x�N�g�������Z����
	void AddAngle(float addAngle);							//�p�x�Ɏw��ʉ��Z����
	void AddMoveVolume(float addVolume);					//�ړ��ʂɎw��ʉ��Z����
	void AddAngleMoveVec();									//�p�x�ƈړ��ʂ���x�N�g�����Z�o���A�ړ��x�N�g���ɉ��Z����
	void UpdatePos();										//�ړ��x�N�g���ʂ����W�ɉ��Z����(������)

	const Math::Vec2&	GetPos() const;			//���W���擾����
	const Math::Vec2&	GetMoveVec() const;		//�ړ��x�N�g�����擾����
	float				GetAngle() const;		//�p�x���擾����
	float				GetMoveVolume() const;	//�ړ��ʂ��擾����
};