#include "System.h"

#include "Move.h"

//�R���X�g���N�^(���W�A�ړ��x�N�g����0)
Move::Move():
	pos(0, 0),
	moveVec(0, 0){}

//�R���X�g���N�^(���W�A�ړ��x�N�g����C�ӂ̐��l�ɐݒ�)
Move::Move(	const Math::Vec2&	pos,
			const Math::Vec2&	moveVec,
			float				angle,
			float				moveVolume) :
	pos(pos),
	moveVec(moveVec),
	angle(angle),
	moveVolume(moveVolume){}


//���WX��ݒ�
void Move::SetPosX(float posX)
{
	pos.x = posX;
}
//���WY��ݒ�
void Move::SetPosY(float posY)
{
	pos.y = posY;
}
//�p�x��ݒ�
void Move::SetAngle(float angle)
{
	this->angle = angle;
}
//�ړ��ʂ�ݒ�
void Move::SetVolume(float moveVolume)
{
	this->moveVolume = moveVolume;
}


//�ړ��x�N�g�����[���N���A����
void Move::ClearMoveVec()
{
	moveVec = Math::Vec2(0, 0);
}
//�ړ��x�N�g���Ɏw��x�N�g�������Z����
void Move::AddMoveVec(const Math::Vec2& addVec)
{
	moveVec += addVec;
}
//�p�x�Ɏw��ʉ��Z����
void Move::AddAngle(float addAngle)
{
	angle += addAngle;
}
//�ړ��ʂɎw��ʉ��Z����
void Move::AddMoveVolume(float addVolume)
{
	moveVolume += addVolume;
}
//�p�x�ƈړ��ʂ���x�N�g�����Z�o���A�ړ��x�N�g���ɉ��Z����
void Move::AddAngleMoveVec()
{
	AddMoveVec(Math::Vec2(
		cosf(angle) * moveVolume,
		sinf(angle) * moveVolume)
	);
}
//�ړ��x�N�g���ʂ����W�ɉ��Z����(������)
void Move::UpdatePos()
{
	pos += moveVec;
}
//��ʊO�ɏo�Ȃ��ړ�
void Move::NotScreenOutUpdatePos(const Math::Box2D& rect)
{
	for (int i = 0; i < 2; ++i)
	{
		float estxy, *posxy;
		if (i == 0)
		{
			estxy = moveVec.x;
			posxy = &pos.x;
		}
		else
		{
			estxy = moveVec.y;
			posxy = &pos.y;
		}

		while (estxy != 0.f)
		{
			float cpyPos = *posxy;
			if		(estxy > 1.f)	{ *posxy += 1.f;	estxy -= 1.f; }
			else if (estxy < -1.f)	{ *posxy -= 1.f;	estxy += 1.f; }
			else					{ *posxy += estxy;	estxy = 0; }
			if (!System::WindowInBox(rect.OffsetCpy(pos)))
			{
				*posxy = cpyPos;
				break;
			}
		}
	}
}


//���W���擾����
const Math::Vec2& Move::GetPos() const
{
	return pos;
}
//�ړ��x�N�g�����擾����
const Math::Vec2& Move::GetMoveVec() const
{
	return moveVec;
}
//�p�x���擾����
float Move::GetAngle() const
{
	return angle;
}
//�ړ��ʂ��擾����
float Move::GetMoveVolume() const
{
	return moveVolume;
}