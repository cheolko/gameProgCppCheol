#ifndef	_CHCH_SDL
#define	_CHCH_SDL		"C:\\_CHCH\\Externals\\SDL"
#define	_CHCH_SDL_IMAGE	_CHCH_SDL"\\SDL2_image-2.0.5"
#endif	_CHCH_SDL 

#ifdef	_DEBUG  
#pragma comment(lib, _CHCH_SDL"\\lib\\win\\x86\\SDL2.lib") 
#pragma comment(lib, _CHCH_SDL"\\lib\\win\\x86\\SDL2main.lib") 
#pragma comment(lib, _CHCH_SDL_IMAGE"\\lib\\win\\x86\\SDL2_image.lib") 

//#else
//#pragma comment(lib, _CHCH_SDL"\\build\\x64\\vc15\\lib\\opencv_world451.lib") 
#endif		_DEBUG

#include "Game.h"

int main(int argc, char** argv)
{
	Game game;
	
	bool success = game.Initialize();
	if (success)
	{
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}
