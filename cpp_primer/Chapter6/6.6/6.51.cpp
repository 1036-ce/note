#include <iostream>

void f()
{
	std::cout<<"void f()" << std::endl;
}
void f(int i)
{
	std::cout << "void f(int )" << std::endl;
}

void f(int i, int j)
{
	std::cout << "void f(int, int)" << std::endl;
}

void f(double i, double j = 3.14)
{
	std::cout << "void f(double, double = 3.14)" << std::endl;
}

int main(void)
{
	f(2.56,42);	//error: call of overloaded ‘f(double, int)’ is ambiguous
	f(42);
	f (42, 0);
	f(2.56, 3.14);
	return 0;
}
