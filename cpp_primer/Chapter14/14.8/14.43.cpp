#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

int main(void)
{
	vector<int> vec{2,4,6,8,10};
	auto f = bind(modulus<int>(), _1, 3);
	cout << (find_if(vec.begin(), vec.end(), f) == vec.end()) << endl;
	return 0;
}
