#ifndef	_CHCH_SDL_
#define	_CHCH_SDL_	"C:\\_CHCH\\ExternalFiles\\SDL"
#endif	_CHCH_SDL_ 

#ifdef	_DEBUG  
#pragma comment(lib, _CHCH_SDL_"\\lib\\win\\x86\\SDL2.lib") 
#pragma comment(lib, _CHCH_SDL_"\\lib\\win\\x86\\SDL2main.lib") 
#pragma comment(lib, _CHCH_SDL_"\\lib\\win\\x86\\SDL2.dll") // 
//#else
//#pragma comment(lib, _CHCH_SDL_"\\build\\x64\\vc15\\lib\\opencv_world451.lib") 
////#pragma comment(lib, _CHCH_SDL_"\\build\\x64\\vc15\\bin\\opencv_world451.dll")
#endif		_DEBUG

#include "SDL.h"
#include "Game.h"

//int MySDL_Initialize()
//{
//    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
//
//    SDL_Window* window = NULL;
//     
//    window = SDL_CreateWindow(  
//        "Cheol's SDL2 test window", 
//        SDL_WINDOWPOS_UNDEFINED, 
//        SDL_WINDOWPOS_UNDEFINED,
//        640, 
//        480,
//        SDL_WINDOW_OPENGL
//    );
//
//    SDL_Renderer* renderer = NULL;
//    renderer = SDL_CreateRenderer(
//        window,
//        -1,
//        SDL_RENDERER_ACCELERATED);
//     
//    //////////////////////////
//    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
//    SDL_RenderClear(renderer);
//    SDL_RenderPresent(renderer);
//
//    SDL_Delay(3000);
//
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//    //////////////////////////
//
//    return 0;
//}

int main(int argc, char* argv[])
{
    //MySDL_Initialize();
    Game    game;

    bool success = game.Initialize();
    if (success)
    {
        game.RunLoop();
    }
    game.Shutdown();

    return 0;
}
