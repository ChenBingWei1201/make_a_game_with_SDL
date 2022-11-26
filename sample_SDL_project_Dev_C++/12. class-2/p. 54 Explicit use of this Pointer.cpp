#include <iostream>
#include <cmath>
#include <graphics.h>
class elipso
{
	private:
		int x, y, a, b, c;
	public:
		void initialize(int, int, int, int);
		void show();
		double area() {return 3.14159*a*b;}	
		double get_major() {return 2*(a>b?a:b);}
		double get_minor() {return 2*(a>b?b:a);}	
		void get_center(int *x0, int *y0) {
		*x0=x; *y0=y;}
		elipso* set_major(int);
		elipso* set_minor(int);
		void set_center(int x0, int y0) {
		x=x0;y=y0;}
};
void elipso::show() 
{
	ellipse(x, y, 0, 360, a, b);
	circle(x+c, y, 1); 
	circle(x-c, y, 1);
}
void elipso::initialize(int x0, int y0, int a0, int b0) 
{
	x=x0; y=y0; a=a0; b=b0;
	c=sqrt(abs(a*a-b*b));
	show();
}
elipso* elipso::set_major(int x0)
{
	if (x0<get_minor()) return (this);
	if (a>b) a=x0/2; 
	else b=x0/2;
	c=sqrt(abs(a*a-b*b));
	return (this);
}
elipso* elipso::set_minor(int y0) 
{
	if (y0>get_major()) return (this);
	if (a>b) b=y0/2;
	else a=y0/2;
	c=sqrt(abs(a*a-b*b));
	return (this);
}
int main(int argc, char*argv[])
{
	initwindow(800, 600); cleardevice();
//	elipso e;
	elipso *e1, *e2;
//	e1 -> initialize(100, 100, 50, 30);
//	e.set_major(80);
	e1 -> set_major(80) -> set_minor(30);
//	e2 -> set_minor(30) -> set_major(50);
	e1->set_center(200, 200);	
	e1->show();
//	e2->show();
	getch(); closegraph();
}
