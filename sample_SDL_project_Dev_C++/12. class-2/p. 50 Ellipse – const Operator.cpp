#include <iostream>
#include <cmath>
#include <graphics.h>
using namespace std;
class elipso
{
	int x, y, a, b, c;
	const double PI;
	public:
		elipso(int r) : PI(3.14) {x=y=r; a=b=r; c=0;}
		elipso(int, int, int, int);
		double area() const {return PI*a*b;}
		void show();
};
void elipso::show()
{
	ellipse(x, y, 0, 360, a, b);
	circle(x+c, y, 1);
	circle(x-c, y, 1);
}
elipso::elipso(int x0, int y0, int a0, int b0) : PI(3.14159)
{
	x=x0; y=y0; a=a0; b=b0;
	c=sqrt(abs(a*a-b*b));
}
int main(int argc, char*argv[])
{
	initwindow(800, 600); cleardevice();
	elipso x(200, 200, 50, 30);
	const elipso y(50);
	x.show(); // non-const obj non-const func
	cout << "y.area = " << y.area() << endl; // non-const obj const func
	getch(); closegraph();
} 
