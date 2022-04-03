// url: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size(), l = 0, r = n - 1;
		int flag = nums[r];
		while (l < r) {
			int m = l + (r - l) / 2;
			if (nums[m] > flag)
				l = m + 1;
			else
				r = m;
		}
		return nums[l];
	}
};

int main(void)
{
	vector<int> nums{3,4,5};
	Solution s;
	cout << s.findMin(nums) << endl;
	return 0;
}
