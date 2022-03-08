#include <iostream>

using namespace std;

class Base {
	int a;
};

class Derived: public Base
{
	int b;
};

int main(void)
{
	Base b1;
	Derived d1;
	b1 = d1;
	return 0;
}
