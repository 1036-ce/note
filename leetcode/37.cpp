// url: https://leetcode-cn.com/problems/maximum-subarray/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// dp[i] = max(dp[i - 1] + nums[i], nums[i]);
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int dp = 0;
		int ans = -100000;
		for (int i = 0; i < n; ++i) {
			dp = max(dp + nums[i], nums[i]);
			ans = max(ans , dp);
		}

		return ans;
	}
};

int main(void)
{
	vector<int> nums{-2,-1};
	Solution s;
	cout << s.maxSubArray(nums) << endl;
	return 0;
}
