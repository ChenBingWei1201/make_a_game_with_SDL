/* palette.c  -*- C -*-
 * 
 * To compile:
 * gcc -o palette palette.c -lSDL_bgi -lSDL2
 * 
 * Shows palette cycling with setpalette().
 * 
 * By Guido Gonzato, September 2021.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 * 
 */

// modified after bgidemo.c PaletteDemo ()

#include <graphics.h>

int main (int argc, char *argv[])
{
  int 
    gd = DETECT,
    gm,
    i, j, x, y,
    width, height,
    color;
  struct palettetype
    palette;
  
  initgraph (&gd, &gm, "");
  getpalette (&palette);
  
  width  = getmaxx () / 15;
  height = getmaxy () / 10;

  x = y = 0;
  color = BLUE;

  for (j = 0; j < 10; ++j ) {
    for (i = 0; i < 15 ; ++i) {
      setfillstyle (SOLID_FILL, color++);
      bar (x, y, x + width, y + height);
      x += width + 1;
      color = 1 + (color % (WHITE - 2));
    }
    x = 0;
    y += height + 1;
  }

  int stop = 0;
  while (! stop) {
    setpalette (1 + random(WHITE - 2), random (WHITE) );
    stop = edelay (300);
  }
  getch ();

  setallpalette( &palette );
  getch ();
  closegraph ();
  
}

// ----- end of file palette.c
