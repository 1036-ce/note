#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;		// 定义_1占位符

bool f(int a, int b)
{
	return a < b;
}
int main(void)
{
	vector<int> vec{1,2,-3,4};
	int b = 2;
	auto f1 = bind(f, _1, b);
	auto wc = find_if(vec.begin(), vec.end(), f1);
	for (auto i: vec)
		cout << i << endl;
	return 0;
}
