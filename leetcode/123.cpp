// url: https://leetcode-cn.com/problems/subsets/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> sub;
	int n;
	vector<vector<int>> subsets(vector<int>& nums) {
		n = nums.size();
		// vis.assign(n, 0);
		dfs(nums, 0);
		return ans;
	}

	void dfs(vector<int>& nums, int s) {
		ans.push_back(sub);
		for (int i = s; i != n; ++i) {
			sub.push_back(nums[i]);
			dfs(nums, i + 1);
			sub.pop_back();
		}
	}
};

int main(void)
{
	vector<int> nums{1,2,2};
	Solution s;
	auto ans = s.subsets(nums);
	cout << ans.size() << endl;
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
