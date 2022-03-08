#include <iostream>
#include <string>
#include <vector>

using namespace std;

int f(int &&i)
{
	return i;
}
int main(void)
{
	int i = 2;
	cout << f(std::move(i)) << endl;
	i = 3;
	cout << f(std::move(i)) << endl;
	return 0;
}
