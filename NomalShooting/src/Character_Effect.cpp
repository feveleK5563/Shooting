#include "Character_Effect.h"

//-----------------------------------------------
Character_Effect::Character_Effect(float priority, const ImageData& imageData, const Math::Vec2& pos):
	CharacterAbstract(CharacterID::Effect, priority, State::Active),
	imageDrawer(imageData, Math::Vec2(imageData.size.w / 2.f, imageData.size.h / 2.f), 5.f, false, Color(255, 255, 255))
{
	parameter.UseObjectParameter();
	parameter.objParam->move.SetPos(pos.x, pos.y);
}

//-----------------------------------------------
void Character_Effect::Update(const ROD& data)
{
	if (imageDrawer.Run())
	{
		*parameter.state = State::Delete;
	}
}

//-----------------------------------------------
void Character_Effect::Draw()
{
	imageDrawer.Draw(	parameter.objParam->move.GetPos(),
						3.f,
						0.f,
						false);
}