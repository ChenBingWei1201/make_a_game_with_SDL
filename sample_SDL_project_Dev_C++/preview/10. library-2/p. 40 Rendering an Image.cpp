#include <SDL.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int main(int argc, char*argv[])
{
SDL_Init(SDL_INIT_VIDEO);
SDL_Window* gWindow = SDL_CreateWindow(
"SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
SDL_Renderer *gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
SDL_Surface *gSurface = SDL_LoadBMP("foo.bmp");
SDL_Texture *gTexture = SDL_CreateTextureFromSurface(gRenderer,
gSurface);
SDL_Rect rect = {5, 5, 320, 240};
SDL_RenderCopy(gRenderer, gTexture, NULL, &rect);
//SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
SDL_RenderPresent(gRenderer); SDL_Delay(2000);
SDL_DestroyTexture(gTexture); SDL_FreeSurface(gSurface);
SDL_DestroyRenderer(gRenderer); SDL_DestroyWindow(gWindow);
SDL_Quit();
}
