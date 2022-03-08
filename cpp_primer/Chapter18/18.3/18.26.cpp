#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
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
};

struct MI: public Derived, public Base2 {
	void print(std::vector<double> a)
	{ std::cout << "MI" << std::endl; }
	void print(int a)
	{ std::cout << "MI::print(int)" << std::endl; }
protected:
	int *ival;
	std::vector<double> dvec;
};

int main(void)
{
	MI mi;
	mi.print(42);
	return 0;
}
