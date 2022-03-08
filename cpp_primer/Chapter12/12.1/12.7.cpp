#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> f1()
{
	return make_shared<vector<int>>();
}

shared_ptr<vector<int>> f2()
{
	auto vec = f1();
	int a;
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
}
int main(void)
{
	f3();
	return 0;
}
