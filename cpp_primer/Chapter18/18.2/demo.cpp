#include <iostream>
#include <string>

void print(std::string s)
{
	std::cout << s << std::endl;
}

namespace primerLib {
	void computer() { print("\' \'");};
	void computer(const void *) { print("const void *");}
}

/* using namespace primerLib; */
void computer(int) { print("int");}
void computer(double, double = 3.14) { print("double double"); }
void computer(char*, char* = 0) { print("char* char*"); }

void f()
{
	using namespace primerLib;
	computer();
}

int main(void)
{
	f();
	return 0;
}
