#include <iostream>
#include <cmath>
#include <graphics.h>
class elipso
{
	public:
		int x, y, a, b, c;
	public:
		void initialize(int, int, int, int);
		void show();
		double area() 
		{
			return 3.14159*a*b;
		}
		double get_major() 
		{
			return 2*(a>b?a:b);
		}
		double get_minor() 
		{
			return 2*(a>b?b:a);
		}
		void get_center(int *x0, int *y0) 
		{
			*x0 = x; 
			*y0 = y;
		}
		void set_major(int);
		void set_minor(int);
		void set_center(int x0, int y0) 
		{
			x = x0;
			y = y0;
		}
};
void elipso::show() 
{
	ellipse(x, y, 0, 360, a, b);
	circle(x+c, y, 1); 
	circle(x-c, y, 1);
}
void elipso::initialize(int x0, int y0, int a0, int b0) 
{
	x = x0; 
	y = y0; 
	a = a0; 
	b = b0;
	c = sqrt(abs(a*a - b*b));
	// show();
}
void elipso::set_major(int x0)
{
	if (x0 < get_minor()) 
		return;
	if (a > b) 
		a = x0/2;
	else 
		b = x0/2;
	c = sqrt(abs(a*a - b*b));
}
void elipso::set_minor(int y0) 
{
	if (y0 > get_major()) 
		return;
	if (a > b) 
		b = y0/2;
	else 
		a = y0/2;
	c = sqrt(abs(a*a-b*b));
}
int main(int argc, char*argv[])
{
	initwindow(800, 600); 
	cleardevice();
	elipso e;
	e.initialize(100, 100, 50, 30);
	e.set_major(800);
	e.set_minor(600);
	e.set_center(400, 300);
	e.show();
	std::cout << e.a << "\n" << e.b;
	getch(); 
	closegraph();
}

