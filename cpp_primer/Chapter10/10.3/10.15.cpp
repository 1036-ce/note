#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int a = 2, b = 12;
	auto f = [a] (int &b) -> int {return a + b;};
	cout << f(b) << endl;
	return 0;
}

