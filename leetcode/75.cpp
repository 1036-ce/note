// url: https://leetcode-cn.com/problems/maximum-length-of-subarray-with-positive-product/

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// posi[i] = posi[i - 1] + 1							nums[i] > 0
	// nega[i] = nega[i - 1] == 0 ? 0 : nega[i - 1] + 1		nums[i] > 0
	// posi[i] = nega[i - 1] == 0 ? 0 : nega[i - 1] + 1		nums[i] < 0
	// nega[i] = posi[i - 1] + 1							nums[i] < 0
	int getMaxLen(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		int posi = 0, nega = 0;
		if (nums[0] > 0)
			posi = 1;
		else if (nums[0] < 0)
			nega = 1;
		ans = max(ans, posi);
		for (int i = 1; i != n; ++i) {
			if (nums[i] > 0) {
				posi = posi + 1;
				nega = nega == 0 ? 0 : nega + 1;
			}
			else if (nums[i] < 0) {
				int tmp = posi;
				posi = nega == 0 ? 0 : nega + 1;
				nega = tmp + 1;
			}
			else
				posi = nega = 0;
			ans = max(ans, posi);
		}
		return ans;
	}
};

int main(void)
{
	vector<int> num{1,-2,-3,4};
	Solution s;
	cout << s.getMaxLen(num) << endl;
	return 0;
}
