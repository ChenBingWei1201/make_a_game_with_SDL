#include <iostream>
using namespace std;
class elipso
{
	public:
		elipso(int);
		~elipso();
	private:
	int id;
};
elipso::elipso(int i)
{
	id = i; cout << "Object ID = " << id << " constructor called" 
	<< endl;
}
elipso::~elipso()
{
	cout << "Object ID = " << id << " destructor called" << endl;
}

elipso first(1);
void func();
int main()
{
	cout << "main() execution begins" << endl;
	elipso second(2);
	static elipso third(3);
	func();
	cout << "main() execution resumes" << endl;
	elipso fourth(4);
	cout << "main() execution ends" << endl;
}
void func()
{
	cout << "func() execution begins" << endl;
	elipso fifth(5);
	static elipso sixth(6);
	cout<< "func() execution ends" << endl;
}
