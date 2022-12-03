#include <SDL.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int main(int argc, char*argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0) return 0;
	SDL_Window* gWindow = SDL_CreateWindow(
		"SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(gWindow == NULL) return 0;
	SDL_Surface* gScreenSurface = SDL_GetWindowSurface(gWindow);
	SDL_FillRect(gScreenSurface, NULL, 
	SDL_MapRGB(gScreenSurface->format, 0x77, 0xA8, 0x48));
	SDL_UpdateWindowSurface(gWindow);
	SDL_PumpEvents();
	SDL_Delay(2000); // wait for 2 seconds
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
}
