#include "InputState.h"

#include "Behavior.h"

//�W���C�p�b�h�ő��삷��
bool BF::ControllJpad(CharacterAbstract& chara, const ROD& data)
{
	if (Input::joypad1.GetVolumeStickL() > 0.f)
	{
		chara.GetParameterRef().move->SetAngle(Input::joypad1.GetAngleStickL());
		chara.GetParameterRef().move->SetVolume(8.f);
		chara.GetParameterRef().move->AddAngleMoveVec();
		return true;
	}
	return false;
}