#include <cstdint>
#include <exception>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <new>
#include <stdexcept>
#include <string>
#include <memory>

using namespace std;

void f(int a) noexcept
{
}

void g(int a) {}

int main(void)
{
	try {
		string("asd").substr(10);
	} catch (exception o) {
		cout << o.what() << endl;
	}
	return 0;
}
