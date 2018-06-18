#include <random>
#include "CharacterFactory.h"

#include "Character_EnemyCreator.h"

//-----------------------------------------------------------------------------
Character_EnemyCreator::Character_EnemyCreator(float priority):
	CharacterAbstract(CharacterID::EnemyCreator, priority, State::Active),
	mtrand(rd())
{
	
}

//-----------------------------------------------------------------------------
void Character_EnemyCreator::Update(const ROD& data)
{
	if (parameter.timeCnt->GetNowCntTime() % 160 == 0)
	{
		CharacterFactory factry;
		float posy = float(mtrand() % (System::windowSizeY - 100) + 50);

		switch (mtrand() % 1)
		{
		case 0:
			for (int i = 0; i < 5; ++i)
			{
				createdCharacter.emplace_back(
					factry.CreateEnemy(
						3,
						BF::MoveFuwaFuwa,
						Image::imageLoader.GetImageData(ImageName::EnemyImage),
						Math::Vec2(float(System::windowSizeX + 50 + (i * 64)),
							posy),
						Color(255, 50, 0)
					)
				);
			}
			break;

		case 1:
			break;
		}
	}

	parameter.timeCnt->Run();
}

//-----------------------------------------------------------------------------
void Character_EnemyCreator::Draw()
{

}