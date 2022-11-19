#include <iostream>
#include <cmath>
#include <cstdlib>
#include <graphics.h>
using namespace std;
class elipso
{
	
	public:
		int r;
		const double PI;
		static int count;
	
		elipso(int x);
		static int get_count() {return count;}
};
int elipso::count = 5;
elipso::elipso(int x) : PI(3.14159)
{
	count++; r=x/count ;
	circle(rand()%getmaxx(), rand()%getmaxy(), r);
//	cout << r << endl;
}
int main(int argc, char*argv[])
{
	initwindow(800, 600); cleardevice();
	cout << "# of circles before is " << elipso::get_count() << endl;
	elipso *c1 = new elipso(100);
	elipso *c2 = new elipso(100);
	elipso *c3 = new elipso(100);
//	cout << c3-> r;
	cout << "# of circles is " << c3->get_count() << endl;
	delete c1;
	delete c2;
	delete c3;
	cout << "# of circles after is " << elipso::get_count() << endl;
	getch(); closegraph();
//	return 0;
}
