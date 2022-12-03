#include <iostream>
#include <cmath>
using namespace std;
class point
{
	int x, y;
	public:
		point(int i=0, int j=0);
		point(const point& p);
		~point();
};
point::point(int i, int j) : x(i), y(j)
{
	cout<< "constructor for point (" << x << ", " << y << ")" <<endl;
}
point::point(const point& p) : x(p.x), y(p.y)
{
	cout<< "CONSTRUCTOR for point (" << p.x << ", " << p.y << ")" <<endl;
}
point::~point()
{
	cout<< "destructor for point (" << x << ", " << y << ")" <<endl;
}
class elipso
{
	private:
		int a, b, c;
		point center;
	public:	
		elipso(const point &o, int a0, int b0);
		~elipso();
};
elipso::elipso(const point &o, int a0, int b0)
: center(o), a(a0), b(b0), c(sqrt(abs(a*a-b*b)))
{
	cout << "constructor for elipso"<< endl;
}
elipso::~elipso()
{
	cout << "destructor for elipso" << endl;
}
int main()
{
	point p(100, 100);
	elipso z(p, 50, 30);
}
