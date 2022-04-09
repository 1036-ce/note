// url: https://leetcode-cn.com/problems/subsets-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> sub;
	int n;
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		n = nums.size();
		sort(nums.begin(), nums.end());
		dfs(nums, 0);
		return ans;
	}

	void dfs(vector<int>& nums, int s) {
		ans.push_back(sub);
		vector<int> vis(22, 0);
		for (int i = s; i != n; ++i) {
			if (vis[10 + nums[i]] == 0) {
			    vis[10 + nums[i]] = 1; 
				sub.push_back(nums[i]);
				dfs(nums, i + 1);
				sub.pop_back();
			}
		}
	}
};

int main(void)
{
	vector<int> nums{4,1,4};
	Solution s;
	auto ans = s.subsetsWithDup(nums);
	cout << ans.size() << endl;
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
