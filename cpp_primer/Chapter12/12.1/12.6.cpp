#include <iostream>
#include <vector>
#include <memory>

using namespace std;

vector<int> *f1()
{
	return new vector<int>;
}

vector<int> *f2()
{
	int a;
	auto vec = f1();
	while (cin >> a)
		vec->push_back(a);
	return vec;
}

void f3()
{
	auto vec = f2();
	auto it = vec->begin();
	while (it != vec->end())
	{
		cout << *it << endl;
		++it;
	}
	delete vec;
}

int main(void)
{
	f3();
	return 0;
}
