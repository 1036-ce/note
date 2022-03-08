#include <iostream>

using namespace std;

class If_then_else {
public:
	int operator()(int a, int b, int c)
	{
		if (a)
			return b;
		else
			return c;
	}
};

int main(void)
{
	int a = 1, b = 2, c = 3;
	If_then_else ite;
	cout << ite(a,b,c) << endl;
	a = 0;
	cout << ite(a,b,c) << endl;
	return 0;
}
