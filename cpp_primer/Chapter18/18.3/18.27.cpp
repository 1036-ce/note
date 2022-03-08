#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <sys/types.h>
#include <vector>

struct Base1 {
	void print(int a) const
	{ std::cout << "Base1" << std::endl; }
protected:
	int ival;
	double dval;
	char cval;
private:
	int *id;
};

struct Base2 {
	void print(double a) const
	{ std::cout << "Base2" << std::endl; }
protected:
	double fval;
private:
	double dval;
};

struct Derived: public Base1 {
	void print(std::string a) const
	{ std::cout << "Derived" << std::endl; }
protected:
	std::string sval;
	double dval;
private:
	int *d;
};

struct MI: public Derived, public Base2 {
	void print(std::vector<double> a)
	{ std::cout << "MI" << std::endl; }
	void foo(double);
protected:
	int *ival;
	std::vector<double> dvec;
};

int ival;
double dval = 1;
void MI::foo(double cval)
{
	int dval ;
	Derived::sval[0] = Base1::cval;
	std::cout << dval<< std::endl;
}
int main(void)
{
	MI mi;
	mi.foo(1);
	return 0;
}
