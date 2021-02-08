#include "Ship.h"

Ship::Ship(Game* game)
	:Actor(game)
	, mRightSpeed(0.0f)
	, mDownSpeed(0.0f)
{
}

void Ship::UpdateActor(float deltaTime)
{
}

void Ship::ProcessKeyboard(const uint8_t* state)
{
}
