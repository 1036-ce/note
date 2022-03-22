// url: https://leetcode-cn.com/problems/jump-game/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return true;
		bool dp[n + 1]; 
		memset(dp, false, sizeof(bool) * (n + 1));
		dp[n - 1] = true;
		int pos = n - 1;
		for (int i = n - 2; i >= 0; --i) {
			if (i + nums[i] >= pos) {
				dp[i] = true;
				pos = i;
			}
		}
		return dp[0];
	}
};

int main(void)
{
	vector<int> nums{2,3,1,1,4};
	Solution s;
	cout << s.canJump(nums) << endl;
	return 0;
}
