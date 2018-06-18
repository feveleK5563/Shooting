#include "DxLib.h"
#include "Math.h"

#include "CharacterDatabase.h"

//�f�[�^��ǉ�����
void CharacterDatabase::AddCharacterData(const CharacterParameter& parameter)
{
	this->data.emplace_back(std::make_shared<ROCharacterParameter>(parameter));
}

//�ێ����Ă���f�[�^��S�č폜����
void CharacterDatabase::ClearCharacterData()
{
	data.clear();
	data.shrink_to_fit();
}

//�f�[�^�̂܂Ƃ߂�Ԃ�
const ROD& CharacterDatabase::GetCharacterData()
{
	return data;
}

//�f�[�^���瓖���蔻���`�𒲂ׂĕ`�悷��
void CharacterDatabase::DrawHitBase()
{
	int color = GetColor(255, 255, 255);

	for (const auto& it : data)
	{
		if (it->objParam == nullptr)
			continue;

		Math::Box2D box = (it->objParam->hitBase);

		DrawBox(box.x, box.y, 
				box.x + box.w, box.y + box.h,
				color, false);
	}
}