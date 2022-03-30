// url: https://leetcode-cn.com/problems/permutations/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<vector<int>> permute(vector<int>& nums) {
	}
};

int main(void)
{
	vector<int> nums{1,2,3};
	Solution s;
	auto ans = s.permute(nums);
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
