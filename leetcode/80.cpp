// url: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int n = nums.size(), l = 0, r = n - 1;
		if (n == 0) 
			return {-1, -1};
		int left, right;
		while (l < r) {
			int m = l + (r - l + 1) / 2;
			if (nums[m] <= target)
				l = m;
			else
				r = m - 1;
		}
		right = l;
		l = 0, r = n - 1;
		while (l < r) {
			int m = l + (r - l) / 2;
			if (nums[m] >= target)
				r = m;
			else
				l = m + 1;
		}
		left = l;
		if (nums[left] != target)
			return {-1, -1};
		return {left, right};
	}
};

int main(void)
{
	vector<int> nums{};
	Solution s;
	auto ans = s.searchRange(nums, 0);
	cout << ans[0] << ' ' << ans[1] << endl;
	return 0;
}
