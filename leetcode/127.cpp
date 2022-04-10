// url: https://leetcode-cn.com/problems/permutations-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> vis;
	vector<int> tmp;
	int n;
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		n = nums.size();
		vis.assign(n, 0);
		dfs(nums, 0);
		return ans;
	}

	void dfs(vector<int>& nums, int cnt) {
		if (cnt == n)
			ans.push_back(tmp);
		vector<int> v1(22, 0);
		for (int i = 0; i != n; ++i) {
			if (vis[i] == 0) {
				if (v1[11 + nums[i]] == 1)
					continue;
				v1[11 + nums[i]] = 1;
				vis[i] = 1;
				tmp.push_back(nums[i]);
				dfs(nums, cnt + 1);
				tmp.pop_back();
				vis[i] = 0;
			}
		}
	}
};

int main(void)
{
	vector<int> nums{1,2,1};
	Solution s;
	auto ans = s.permuteUnique(nums);
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
