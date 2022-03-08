#include <iostream>
#include <vector>

using namespace std;

int f(int, int);

vector<decltype(f)*> vec;

int main(void)
{
	vec.push_back(f);
	return 0;
}

int f(int a,int b)
{
	return 1;
}
