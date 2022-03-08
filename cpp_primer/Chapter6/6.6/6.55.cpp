#include <iostream>
#include <vector>

using namespace std;

int add(int, int);
int sub(int, int);
int mul(int, int);
int div1(int, int);

vector<decltype(add)*> vec;

int main(void)
{
	vec.push_back(add);
	vec.push_back(sub);
	vec.push_back(mul);
	vec.push_back(div1);
	return 0;
}

int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div1(int a, int b)
{
	return a / b;
}

