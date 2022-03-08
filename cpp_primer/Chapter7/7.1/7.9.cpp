#include <iostream>
#include <istream>
#include <ostream>
#include <string>

struct Person {
	std::string name;
	std::string address;

	std::string getName() const{ return name; }
	std::string getAddress() const { return address; }
};

std::istream &read(std::istream &is, Person &p)
{
	is >> p.name >> p.address;
	return is;
}

std::ostream &print(std::ostream &os, const Person &p) 
{
	os << p.getName() << " " << p.getAddress() << " ";
	return os;
}

int main(void)
{
	Person p;
	read(std::cin, p);
	print(std::cout, p) << std::endl;
	return 0;
}
