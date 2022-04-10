// url: https://leetcode-cn.com/problems/combination-sum-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	// vector<int> vis;
	vector<int> tmp;
	int n;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		n = candidates.size();
		// vis.assign(55, 0);
		dfs(candidates, target, 0);
		return ans;
	}

	void dfs(vector<int>& candidates, int target, int s) {
		if (target == 0)
			ans.push_back(tmp);
		if (target < 0)
			return;
		for (int i = s; i != n; ++i) {
			tmp.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], i + 1);
			tmp.pop_back();
			while (i < n - 1 && candidates[i + 1] == candidates[i])
				++i;
		}
	}
};

int main(void)
{
	vector<int> nums{10,1,2,7,6,1,5};
	Solution s;
	auto ans = s.combinationSum2(nums, 8);
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
