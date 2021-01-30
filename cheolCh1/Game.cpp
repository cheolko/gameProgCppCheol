#include "Game.h"
#include <iostream>

using namespace std;

const int thickness = 15;
const float paddleH = 100.0f;

const float screenW = 1024.0f;
const float screenH = 768.0f;

Game::Game()
	: mWindow(nullptr),
	mRenderer(nullptr),
	mTicksCount(0),
	mIsRunning(true),
	mPaddleDir(0)
	{
}

bool	Game::Initialize()
{
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	mWindow = SDL_CreateWindow(
		"Hangul �ѱ�", // Window title
		100,	// Top left x-coordinate of window
		100,	// Top left y-coordinate of window
		1024,	// Width of window
		768,	// Height of window
		0		// Flags (0 for no flags set)
	);
	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}
	
	mRenderer = SDL_CreateRenderer(
		mWindow, // Window to create renderer for
		-1,		 // Usually -1
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}
	
	//////////////
	mPaddlePos.x = 10.0f;
	mPaddlePos.y = 768.0f / 2.0f;

	mBallPos.x = 1024.0f / 2.0f;
	mBallPos.y = 768.0f / 2.0f;

	mBallVel.x = -200.0f;
	mBallVel.y = 235.0f;

	return true;
}

void	Game::RunLoop()
{
	while (mIsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void	Game::Shutdown()
{
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void	Game::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:	// other events: http://wiki.libsdl.org/SDL_EventType 
			mIsRunning = false;
			break;
		} 
	}

	const Uint8*	state = SDL_GetKeyboardState(NULL);
	//cout << state[SDL_SCANCODE_ESCAPE] << endl;
	if (state[SDL_SCANCODE_ESCAPE])
		mIsRunning = false;

	mPaddleDir = 0; // 
	if (state[SDL_SCANCODE_W])
	{
		mPaddleDir -= 1;
	}
	if (state[SDL_SCANCODE_S])
	{
		mPaddleDir += 1;
	}

}

void	Game::UpdateGame()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount+16))
		;

	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f; // to second

	// Clamp maximum delta time value
	if (deltaTime > 0.05f)  
		// 50ms. 1s/60fps * 1000 ==> 16.66ms���� �ؾ��� �ʳ�?
	{
		deltaTime = 0.05f;
	}

	// Update tick counts (for next frame)
	mTicksCount = SDL_GetTicks();

	// Update paddle position based on direction
	if (mPaddleDir != 0)
	{
		mPaddlePos.y += mPaddleDir * 300.0f * deltaTime;

		if (mPaddlePos.y < (paddleH / 2.0f + thickness))
			mPaddlePos.y = paddleH / 2.0f + thickness;
		else if (mPaddlePos.y > (768.0f - paddleH / 2.0f - thickness))
			mPaddlePos.y = 768.0f - paddleH / 2.0f - thickness;
	}

	// Update ball position based on ball velocity
	mBallPos.x += mBallVel.x * deltaTime;
	mBallPos.y += mBallVel.y * deltaTime;

	// Bounce if needed
	// Did we intersect with the paddle?
	float diff = mPaddlePos.y - mBallPos.y;
	// Take absolute value of difference
	diff = (diff > 0.0f) ? diff : -diff;

	
	if(mBallPos.x <= 0.f)
		mIsRunning = false;
	// right wall
	else if (mBallVel.x > 0.f &&
		(mBallPos.x + thickness / 2.0f) > (screenW - thickness))
		mBallVel.x *= -1.f;
	// top wall
	else if (mBallVel.y < 0.f &&
			(mBallPos.y - thickness) < thickness)
		mBallVel.y *= -1.f;
	// bottom wall
	else if (mBallVel.y > 0.f &&
		(mBallPos.y + thickness) > screenH - thickness)
		mBallVel.y *= -1.f;
	else if (diff <= paddleH/2.f &&
		(mBallPos.x - mPaddlePos.x) <= (10.f+thickness/2.f) &&
		mBallVel.x < 0.f)
		mBallVel.x *= -1.f;
}

void	Game::GenerateOutput()
{
	// Clear back buffer
	SDL_SetRenderDrawColor(
		mRenderer,
		0,		// R
		0,		// G 
		255,	// B
		255		// A
	);

	SDL_RenderClear(mRenderer);

	///////
	// Draw something...

	SDL_SetRenderDrawColor(mRenderer, 255, 255, 0, 255);

	// Draw top wall
	SDL_Rect wall{
		0,			// Top left x
		0,			// Top left y
		1024,		// Width
		thickness	// Height
	};

	SDL_RenderFillRect(mRenderer, &wall);

	// Draw bottom wall
	wall.y = 768 - thickness;
	SDL_RenderFillRect(mRenderer, &wall);

	// Draw right wall
	wall.x = 1024 - thickness;
	wall.y = 0;
	wall.w = thickness;
	wall.h = 768 - thickness; // by cheol
	SDL_RenderFillRect(mRenderer, &wall);

	// Draw ball
	SDL_Rect	ball{
		static_cast<int>(mBallPos.x - thickness/2),
		static_cast<int>(mBallPos.y - thickness/2),
		thickness,
		thickness
	};
	SDL_RenderFillRect(mRenderer, &ball);

	// Draw paddle
	SDL_Rect	paddle{
		static_cast<int>(mPaddlePos.x),
		static_cast<int>(mPaddlePos.y - paddleH / 2),
		thickness,
		static_cast<int>(paddleH)
	};
	SDL_RenderFillRect(mRenderer, &paddle);

	////// 

	// Swap front buffer and back buffer
	SDL_RenderPresent(mRenderer);

}
