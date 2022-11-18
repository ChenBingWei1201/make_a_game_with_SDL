#include <graphics.h>
#include <ctime>
int main(int argc, char*argv[])
{
	initwindow(0, 0); // full screen
	setcolor(RED);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	time_t now; tm* timeinfo;
	char buffer [80];
	while(true) {
	if (kbhit()) break;
	cleardevice();
	time (&now); timeinfo = localtime(&now);
	strftime(buffer, 80 ,"Now it's %I:%M:%S%p.", timeinfo);
	outtextxy(random(getmaxx()), random(getmaxy()), buffer);
	refresh(); delay(1000);
	}
	closegraph();
}
