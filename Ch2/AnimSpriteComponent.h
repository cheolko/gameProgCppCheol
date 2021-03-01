#pragma once
#include "SpriteComponent.h"
#include <vector>

class AnimSpriteComponent :
    public SpriteComponent
{
private:
	// All textures in the animation
	std::vector<SDL_Texture*> mAnimTextures;
	// Current frame displayed
	float mCurrFrame;
	// Animation frame rate
	float mAnimFPS;

public:
    AnimSpriteComponent(class Actor* owner, int drawOrder = 100);


};

