#pragma once
#include "SDL.h"

struct Vector2 {
	float x;
	float y;
};

class Game
{
	SDL_Window*		mWindow;
	SDL_Renderer*	mRenderer;
	bool			mIsRunning;

	Vector2 mPaddlePos;
	Vector2 mBallPos;
	Vector2 mBallVel;

	Uint32	mTicksCount;

	int		mPaddleDir;

public:
	Game();

	bool	Initialize();
	void	RunLoop();
	void	Shutdown();

private:
	void	ProcessInput();
	void	UpdateGame();
	void	GenerateOutput();



};

