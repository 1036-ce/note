#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned int Bit;
class A {
public:
	Bit mode: 2;
	Bit modified: 1;
	Bit prot_owner: 3;
	Bit prot_group: 3;
	Bit prot_world: 3;
};

int main(void)
{
	cout << sizeof(A) << endl;
	return 0;
} 
