#include <iostream>
#include <cmath>
#include <graphics.h>
class elipso
{
	private:
		int x, y, a, b, c;
	public:
		elipso(int, int, int, int);
		elipso(int r) {x=y=r; a=b=r; c=0; show("1");}
		elipso() {x=y=a=b=10; c=0; show("0");}
		void show(char *s=NULL);
		double area() {return 3.14159*a*b;}
};
elipso::elipso(int x0, int y0, int a0, int b0) 
{
	x=x0; y=y0; a=a0; b=b0;
	c=sqrt(abs(a*a-b*b));
	show("4");
}
void elipso::show(char *s) 
{
	ellipse(x, y, 0, 360, a, b);
	circle(x+c, y, 1); 
	circle(x-c, y, 1);
	if (s) outtextxy(x-textwidth(s)/2, y-textheight(s), s); 
}
int main(int argc, char*argv[])
{
initwindow(800, 600); cleardevice();
elipso x(100, 100, 50, 30), y(50), z(x);
std::cout<< " The area of z is " << z.area() << std::endl;
getch(); closegraph();
}
