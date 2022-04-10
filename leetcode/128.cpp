// url: https://leetcode-cn.com/problems/combination-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> tmp;
	int n;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		n = candidates.size();
		dfs(candidates, 0, target, 0);
		return ans;
	}

	void dfs(vector<int>& candidates, int cur, int target, int s) {
		if (cur > target)
			return;
		if (cur == target)
			ans.push_back(tmp);
		for (int i = s; i != n; ++i) {
			tmp.push_back(candidates[i]);
			dfs(candidates, cur + candidates[i], target, s);
			tmp.pop_back();
			s = s + 1;
		}
	}
};

int main(void)
{
	vector<int> nums{2,3,6,7};
	Solution s;
	auto ans = s.combinationSum(nums, 7);
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
