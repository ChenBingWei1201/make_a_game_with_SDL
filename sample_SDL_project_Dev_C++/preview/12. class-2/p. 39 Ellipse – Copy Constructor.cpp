#include <iostream>
#include <cmath>
#include <graphics.h>
class elipso
{
private:
int x, y, a, b, c;
public:
elipso(int, int, int, int);
elipso(const elipso &x);
void show(char*s=NULL);
double area() {return 3.14159*a*b;}
};
void elipso::show(char *s)
{
ellipse(x, y, 0, 360, a, b);
circle(x+c, y, 1);
circle(x-c, y, 1);
if (s) outtextxy(x-textwidth(s)/2, y-textheight(s), s);
}
elipso::elipso(int x0, int y0, int a0, int b0)
{
x=x0; y=y0; a=a0; b=b0;
c=sqrt(abs(a*a-b*b));
show("4");
}
elipso::elipso(const elipso &e)
{
x=e.x; y=e.y;
a=e.a; b=e.b; c=e.c;
show("copy");
}
int main(int argc, char*argv[])
{
initwindow(800, 600); cleardevice();
elipso x(100, 100, 50, 30), y=x, &z=y;
std::cout << "The area of y is " << y.area() << std::endl;
getch(); closegraph();
}
