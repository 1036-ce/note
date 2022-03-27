// url: https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int dp = nums[0];
		int ans = nums[0];
		for (int i = 1; i != n; ++i) {
			dp = nums[i] + max(dp, 0);
			ans = max(ans, dp);
		}
		return ans;
	}
};

int main(void)
{
	vector<int> vec{-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout << s.maxSubArray(vec) << endl;
	return 0;
}
