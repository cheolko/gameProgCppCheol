#pragma once
#include "SDL.h"
#include <vector>

class Game
{
	SDL_Window*		mWindow;
	SDL_Renderer*	mRenderer;
	Uint32			mTicksCount;
	bool			mIsRunning;

	// Game-specific
	class Ship*		mShip; // Player's ship

	// All the actors in the game
	std::vector<class Actor*> mActors;
	// Any pending actors
	std::vector<class Actor*> mPendingActors; 
	// All the sprite components drawn
	std::vector<class SpriteComponent*> mSprites;

	bool mUpdatingActors;

	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	void LoadData();


public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
	

};

