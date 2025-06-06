// This program demonstrates the override key word.
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void functionA(int arg) const
	{ cout << "This is Base::functionA" << endl; }
};

class Derived : public Base
{
public:
	virtual void functionA(int arg) const override
	{ cout << "This is Derived::functionA" << endl; }
};

int main()
{
	// Allocate instances of the Derived class.
	Base *b = new Derived();  //This is Derived::functionA
	Derived *d = new Derived();  //This is Derived::functionA

	// Call functionA with the two pointers.
	b->functionA(99);
	d->functionA(99);

	return 0;
}
//This is Derived::functionA
//This is Derived::functionA