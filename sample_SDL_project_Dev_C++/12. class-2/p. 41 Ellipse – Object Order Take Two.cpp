#include <iostream>
using namespace std;
class elipso {
public:
elipso(int i) {
id = i;
cout << "Object ID = " << id << " constructor called" << endl;}
~elipso() {
cout << "Object ID = " << id << " destructor called" << endl;}
elipso(const elipso &x) {
id = -1*x.id;
cout << "Object ID = " << id << " copy constructor called "
"(from Object ID = " << x.id << ")" << endl;}
private:
int id;
};
void func(elipso &x)
{
cout << "func() execution begins" << endl;
elipso fifth(5);
cout<< "func() execution ends" << endl;
}
int main()
{
cout << "main() execution begins" << endl;
elipso second(2);
func(second);
cout << "main() execution ends" << endl;
}
