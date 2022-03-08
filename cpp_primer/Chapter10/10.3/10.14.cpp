#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	auto f = [] (int &a, int &b) -> int {return a + b;};
	int a = 12, b = 123;
	cout << f(a,b) << endl;
	return 0;
}

