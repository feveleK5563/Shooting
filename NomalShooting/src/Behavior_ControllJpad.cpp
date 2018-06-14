#include "InputState.h"
#include "System.h"

#include "Behavior.h"

//ジョイパッドで操作する
bool BF::ControllJpad(CharacterAbstract& chara)
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