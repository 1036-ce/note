// url: https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int low = 1, high = 1;
		vector<vector<int>> ans;
		int res = 1;
		while (high != target) {
			if (res == target) {
				vector<int> tmp;
				for (int i = low; i <= high; ++i) 
					tmp.push_back(i);
				ans.push_back(tmp);
				res -= low;
				++low;
			}
			else if (res > target) {
				res -= low;
				++low;
			}
			else {
				++high;
				res += high;
			}
		}
		return ans;
	}
};

int main(void)
{
	Solution s;
	auto ans = s.findContinuousSequence(9);
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
