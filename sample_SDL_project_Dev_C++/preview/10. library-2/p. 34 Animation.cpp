#include <graphics.h>
int main(int argc, char*argv[])
{
	int x = 0, y = 0, dx = 1, dy = 1, r = 100;
	initwindow(640, 480); // window size
	while (1)
	{
		if (kbhit()) break; // a key is hit
		x += dx; y += dy; 
		if (x < r) dx = 1; if (x >= getmaxx() - r) dx = -1;
		if (y < r) dy = 1; if (y >= getmaxy() - r) dy = -1;
		cleardevice(); // for redraw
		setcolor(GREEN); 
		setfillstyle(SOLID_FILL, BLUE);
		fillellipse(x, y, r, r);
		refresh(); delay(10); // update screen
}
	closegraph();
}
