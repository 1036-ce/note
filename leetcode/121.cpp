// url: https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int n = 0;
		for (int i: nums)
			n = n ^ i;
		int m = n & (-n);	// 找到两个只出现一次的数的第一个不同的位，按照这个位进行分组

		vector<int> ans(2);
		for (int i: nums) {
			if (i & m)
				ans[0] ^= i;
			else
				ans[1] ^= i;
		}
		return ans;
	}
};

int main(void)
{
	vector<int> nums{4,1,4,6};
	Solution s;
	auto ans = s.singleNumbers(nums);
	cout << ans[0] << ' ' << ans[1] << endl;
	return 0;
}
