// url: https://leetcode-cn.com/problems/jump-game-ii/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		/* int n = nums.size();
		 * if (n == 0) return 0;
		 * int dp[n];
		 * dp[n - 1] = 0;
		 * int min_num = 0;
		 * for (int i = n - 2; i >= 0; --i) {
		 *     dp[i] = 100010;
		 *     for (int j = i + 1; j <= i + nums[i]; ++j) {
		 *             dp[i] = min(dp[i], dp[j]);
		 *     } 
		 *     ++dp[i];
		 * }
		 * return dp[0]; */
	}
};

int main(void)
{
	vector<int> nums{2,3,1,1,4};
	Solution s;
	cout << s.jump(nums) << endl;
	return 0;
}
