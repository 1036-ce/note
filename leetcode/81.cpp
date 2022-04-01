// url: https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size(), l = 0, r = n - 1;
		int flag = nums[r];
		while (l < r) {
			int m = l + (r - l) / 2;
			if (nums[m] == target)
				return m;
			// 三个条件中任意一个成立或者三个都成立该表达式为真，否则为假
			else if ((target <= flag) ^ (nums[m] > target) ^ (nums[m] > flag))
				l = m + 1;
			else
				r = m - 1;
		}
		return nums[l] == target ? l : -1;
	}
};

int main(void)
{
	vector<int> nums{4,5,6,0,1,2};
	Solution s;
	cout << s.search(nums, 0) << endl;
	return 0;
}
