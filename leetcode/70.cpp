// url: https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			if (nums[l] + nums[r] < target)
				++l;
			else if (nums[l] + nums[r] > target)
				--r;
			else
				return {nums[l], nums[r]};
		}
		return {0, 0};
	}
};

int main(void)
{
	vector<int> nums{2,7,11,15};
	Solution s;
	auto ans = s.twoSum(nums, 9);
	cout << ans[0] << ' ' << ans[1] << endl;
	return 0;
}
