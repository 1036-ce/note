#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

int main(void)
{
	try {
		int a = 12;
		throw a;
	} catch (int a){
		cout << a << endl;
	}

	return 0;
}
