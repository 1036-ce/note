#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Equal {
public:
	bool operator()(int a, int b)
	{
		return a == b;
	}
};

int main(void)
{
	vector<int> vec{1,2,3,1,2,2,5,4,2};
	Equal e;
	replace_if(vec.begin(), vec.end(), [&e](int n) { return e(n, 2); } , 99);
	for (auto i: vec)
		cout << i << endl;
	return 0;
}
