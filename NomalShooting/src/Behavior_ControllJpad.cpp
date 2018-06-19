#include "InputState.h"

#include "Behavior.h"

//�W���C�p�b�h�ő��삷��
bool BF::ControllJpad(CharacterAbstract& chara)
{
	if (Input::joypad1.GetVolumeStickL() > 0.f)
	{
		chara.GetParameterRef().objParam->move.SetAngle(Input::joypad1.GetAngleStickL());
		chara.GetParameterRef().objParam->move.SetVolume(8.f);
		chara.GetParameterRef().objParam->move.AddAngleMoveVec();
		return true;
	}
	return false;
}