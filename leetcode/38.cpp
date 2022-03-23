// url: https://leetcode-cn.com/problems/maximum-sum-circular-subarray/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArraySumCircular(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n - 1; ++i)
			nums.push_back(nums[i]);

		int dp = 0, ans = -100000;
		n = nums.size();
		for (int i = 0; i != n; ++i) {
			dp = max(dp + nums[i], nums[i]);
			ans = max(ans, dp);
		}
		return ans;
	}
};

int main(void)
{
	vector<int> vec{5, -3, 5};
	Solution s;
	cout << s.maxSubArraySumCircular(vec) << endl;
	return 0;
}
