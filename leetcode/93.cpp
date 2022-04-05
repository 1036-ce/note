// url: https://leetcode-cn.com/problems/3sum/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		int n = nums.size();
		for (int i = 0; i != n; ++i) {
			if (i != 0 && nums[i - 1] == nums[i])
				continue;
			int j = i + 1, k = n - 1;
			int target = -nums[i];
			while (j < k) {
				if (nums[j] + nums[k] == target) {
					ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
					while (j < n - 1 && nums[j] == nums[j + 1])
						++j;
					while (k > 0 && nums[k] == nums[k - 1])
						--k;
					++j, --k;
				}
				else if (nums[j] + nums[k] < target) 
					++j;
				else
					--k;
			}
		}
		return ans;
	}
};

int main(void)
{
	vector<int> nums{0,0,0};
	Solution s;
	auto ans = s.threeSum(nums);
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
