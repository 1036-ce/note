// url: https://leetcode-cn.com/problems/permutations/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> vis;
	vector<int> tmp;
	vector<vector<int>> permute(vector<int>& nums) {
		vis.resize(nums.size(), 0);
		dfs(nums, 0);
		return ans;
	}

	void dfs(vector<int>& nums, int num) {
		if (num == nums.size()) {
			ans.push_back(tmp);
			return;
		}
		for (int i = 0; i != nums.size(); ++i) {
			if (vis[i] == 0) {
				vis[i] = 1;
				tmp.push_back(nums[i]);
				dfs(nums, num + 1);
				tmp.pop_back();
				vis[i] = 0;
			}
		}
	}
};

int main(void)
{
	vector<int> nums{1};
	Solution s;
	auto ans = s.permute(nums);
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
