#include "InputState.h"
#include "CharacterFactory.h"

#include "Behavior.h"

//プレイヤー用通常弾を生成する
bool BF::CreateNomalBulletForPlayer(CharacterAbstract& chara, const ROD& data)
{
	if (Input::joypad1[PAD_INPUT_1].GetDurationTime(ON) % 3 == 0)
	{
		CharacterFactory fac;
		chara.GetCreatedCharacterRef().emplace_back(
			fac.CreateNomalBullet(
				CharacterID::PlayerBullet,
				Image::imageLoader.GetImageData(ImageName::NomalBulletImage),
				Math::ToRadian(0.f),
				30.f,
				chara.GetParameterRef().move->GetPos() + Math::Vec2(40, 0)
			)
		);
		return true;
	}
	return false;
}