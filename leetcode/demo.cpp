#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> nums{1,1,1,2,3,2,3,4};
	auto ret = unique(nums.begin(), nums.end());
	vector<int> tmp(nums.begin(), ret);
	for (auto i: tmp)
		cout << i << ' ';
	cout << endl;
	return 0;
}
