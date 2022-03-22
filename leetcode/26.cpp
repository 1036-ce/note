// url: https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size(), l = 0, r = n - 1;
		if (n == 0) return 0;
		int m = l + (r - l) / 2;
		while (l < r) {
			if (nums[m] >= target)
				r = m;
			else
				l = m + 1;
			m = l + (r - l) / 2;
		}
		cout << m << " " << nums[m] << endl;

		int ret = 0;
		while (m < n && nums[m] == target) {
			++ret;
			++m;
		}
		return ret;
	}
};

int main(void)
{
	vector<int> nums{5,7,7,8,8,10};
	Solution s;
	cout << s.search(nums, 5) << endl;
	return 0;
}
