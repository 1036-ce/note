// url: https://leetcode-cn.com/problems/find-peak-element/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size(), l = 0, r = n - 1;
		while (l + 1 < r) {
			int m = l + (r - l) / 2;
			if (nums[m] > nums[m - 1] || m == 0)
				l = m;
			else if (nums[m] < nums[m + 1] || m == n - 1)
				r = m;
			else 
				r = m - 1;
		}
		if (nums[l] > nums[r])
			return l;
		return r;
	}
};

int main(void)
{
	vector<int> nums{1,2,3,1,5,6,4};
	Solution s;
	cout << s.findPeakElement(nums) << endl;
	return 0;
}
