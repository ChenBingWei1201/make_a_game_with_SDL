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
SDL_SetRenderDrawColor(gRenderer, 0, 255, 255, 255);
SDL_Rect src[4] = {{0, 0, 64, 205}, {64, 0, 64, 205}, {128, 0, 64,
205}, {196, 0, 64, 205}};
SDL_Rect dst = {0, 200, 64, 205};
for (int i=0;i<100;i++) {
SDL_RenderClear(gRenderer);
SDL_RenderCopy(gRenderer, gTexture, &src[i%4], &dst);
SDL_RenderPresent(gRenderer); SDL_PumpEvents(); SDL_Delay(400);
dst.x = (dst.x + 64)%SCREEN_WIDTH;
}
SDL_DestroyTexture(gTexture); SDL_FreeSurface(gSurface);
SDL_DestroyRenderer(gRenderer); SDL_DestroyWindow(gWindow);
SDL_Quit();
}
