// url: https://leetcode-cn.com/problems/house-robber-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int size = nums.size();
		if (size == 1) return nums[0];
		int dp[size + 1];
		dp[0] = 0, dp[1] = 0;
		for (int i = 2; i <= size; ++i) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		}
		int ret = dp[size];

		dp[1] = nums[0];
		for (int i = 2; i < size; ++i) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		}
		return max(ret, dp[size - 1]);
	}
};

int main(void)
{
	vector<int> vec{3,2};
	Solution s;
	cout << s.rob(vec) << endl;
	return 0;
}
