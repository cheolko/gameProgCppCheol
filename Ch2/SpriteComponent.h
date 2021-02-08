#pragma once
#include "Component.h"

class SpriteComponent : Component
{
	// (Lower draw order corresponds with further back)
	SpriteComponent(class Actor* owner, int drawOrder = 100);
	~SpriteComponent();



};

