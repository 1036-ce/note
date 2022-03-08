#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> vec(10);
	fill_n(vec.begin(), vec.size(), 0);
	for (auto i: vec)
		cout << i << endl;
	return 0;
}
