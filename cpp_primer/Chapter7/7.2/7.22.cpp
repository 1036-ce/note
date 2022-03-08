#include <iostream>
#include <istream>
#include <ostream>
#include <string>

class Person {
	friend std::istream &read(std::istream&, Person&);
	friend std::ostream &print(std::ostream&, const Person&);
	public:
		Person() = default;
		Person(std::string name): name(name) {}
		Person(std::string name, std::string address): name(name), address(address) {}
		std::string getName() const{ return name; }
		std::string getAddress() const { return address; }

	private:
		std::string name;
		std::string address;
};

std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, const Person&); 

int main(void)
{
	Person p1;
	Person p2("hello");
	Person p3("Hello","world"); 
	print(std::cout,p1)<<std::endl;
	print(std::cout,p2)<<std::endl;
	print(std::cout,p3)<<std::endl; 
	return 0;
}

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
