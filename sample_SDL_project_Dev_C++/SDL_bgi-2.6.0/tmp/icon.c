#include <graphics.h>

int main (int argc, int *argv[])
{
  SDL_Surface *surface;
  
  initwindow (256, 256);
  cleardevice ();
  settextstyle (TRIPLEX_FONT, HORIZ_DIR, 10);
  setcolor (BLUE);
  outtextxy (22, 10, "SDL");
  outtextxy (23, 10, "SDL");
  outtextxy (22, 11, "SDL");
  outtextxy (23, 11, "SDL");
  setcolor (RED);
  outtextxy (32, 80, "BGI");
  outtextxy (33, 80, "BGI");
  outtextxy (32, 81, "BGI");
  outtextxy (33, 81, "BGI");
  refresh ();
  surface = SDL_GetWindowSurface (bgi_window);
  SDL_SaveBMP (surface, "icon.bmp");
  
  getch ();
  closegraph ();
}