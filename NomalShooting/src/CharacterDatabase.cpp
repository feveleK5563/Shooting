#include "DxLib.h"
#include "Math.h"

#include "CharacterDatabase.h"

//�f�[�^��ǉ�����
void CharacterDatabase::AddCharacterData(const CharacterParameter& parameter)
{
	this->data.emplace_back(std::make_unique<ROCharacterParameter>(parameter));
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

//�f�[�^�����`�𒲂ׂĕ`�悷��
void CharacterDatabase::DrawRectAngle()
{
	int color = GetColor(255, 255, 255);

	for (auto it = data.begin();
		 it != data.end();
		 ++it)
	{
		if ((*it)->hitBase == nullptr)
			continue;

		Math::Box2D box = (*(*it)->hitBase);

		DrawBox(box.x, box.y, 
				box.x + box.w, box.y + box.h,
				color, false);
	}
}