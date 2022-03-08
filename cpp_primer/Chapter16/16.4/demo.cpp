#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <memory>
#include "my_make_shared.h"


using namespace std;

int main(void)
{
	auto p = my_make_shared<string>("strsd");
	cout << *p << endl;
	return 0;
}
