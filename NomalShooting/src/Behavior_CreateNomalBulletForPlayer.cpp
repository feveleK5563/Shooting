#include "InputState.h"
#include "CharacterFactory.h"

#include "Behavior.h"

//�v���C���[�p�ʏ�e�𐶐�����
bool BF::CreateNomalBulletForPlayer(CharacterAbstract& chara)
{
	CharacterFactory fac;
	chara.GetCreatedCharacterRef().emplace_back(
		fac.CreateNomalBullet(
			CharacterID::PlayerBullet,
			BF::NomalMove,
			(int)CharacterID::Enemy,
			Image::imageLoader.GetImageData(ImageName::NomalBulletImage),
			Math::ToRadian(0.f),
			30.f,
			chara.GetParameterRef().objParam->move.GetPos() + Math::Vec2(40, 0),
			Color(90, 210, 255)
		)
	);
	return false;
}