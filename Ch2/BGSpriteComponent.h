#pragma once
#include "SpriteComponent.h"
class BGSpriteComponent :
    public SpriteComponent
{
public:
	// Set draw order to default to lower (so it's in the background)
	BGSpriteComponent(class Actor* owner, int drawOrder = 10);





};

