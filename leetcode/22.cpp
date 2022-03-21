// url: https://leetcode-cn.com/problems/house-robber/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
	int rob(vector<int>& nums) {
		int n = nums.size();
		int l = 0, m = nums[0], r = nums[0];
		for (int i = 2; i <= n; ++i) {
			r = max(m, l + nums[i - 1]);
			l = m;
			m = r;
		}
		return r;
	}
};

int main(void)
{
	vector<int> vec{1,2,3,1};
	Solution s;
	cout << s.rob(vec) << endl;
	return 0;
}
