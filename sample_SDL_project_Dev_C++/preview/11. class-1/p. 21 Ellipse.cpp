#include <iostream>
#include <cmath>
#include <graphics.h>
using namespace std;
class elipso
{
	public:
		int x, y, a, b, c;
		void initialize(int x0, int y0, int a0, int b0) 
		{
			x = x0; 
			y = y0; 
			a = a0; 
			b = b0; // set center & semi-axes
			c = sqrt(fabs(a*a - b*b));
			show();
    	}
		void show() 
		{
			ellipse(x, y, 0, 360, a, b); // draw a complete ellipse
			circle(x+c, y, 1); // mark the positive focus
			circle(x-c, y, 1); // mark the negative focus
			circle(x, y, 15);
		}
		double area() 
		{
			return 3.14159*a*b; 
		}
};
int main(int argc, char*argv[])
{
	initwindow(800, 600); 
	cleardevice();
	elipso e;
	e.initialize(100, 100, 50, 30);
	cout << "The area is " << e.area() << endl;
	elipso *p = &e;
	cout << "The center is at (" << p->x << ", " << p->y << ")" << endl;
	getch(); 
	closegraph();
}
