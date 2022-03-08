#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(int a, int sz)
{
	return a > sz;
}
int main(void)
{
	string s("1234567890");
	vector<int> vec{1,1,62,3,6,3,4,13};
	auto t = find_if(vec.begin(), vec.end(), bind(check_size, _1, s.size()));
	cout << *t << endl;
	return 0;
}

