// url: https://leetcode-cn.com/problems/minimum-size-subarray-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
		int left = 0, right = 0;
		int res = 0, ans = 0x3f3f3f3f;

		while (right != n) {
			if (res >= target) {
				ans = min(ans, right - left);
				res -= nums[left++];
			}
			else
				res += nums[right++];
		}
		while (res >= target) {
			ans = min(ans, right - left);
			res -= nums[left++];
		}
		return ans > n ? 0 : ans;
	}
};
int main(void)
{
	vector<int> nums{1,4,4};
	Solution s;
	cout << s.minSubArrayLen(5,nums) << endl;
	return 0;
}
