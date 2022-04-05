// url: https://leetcode-cn.com/problems/subarray-product-less-than-k/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (k <= 1) return 0;
		int prod = 1, left = 0, right = 0;
		int ans = 0;
		int n = nums.size();
		while (right < n) {
			prod *= nums[right];
			while (prod >= k) {
				prod /= nums[left];
				++left;
			}
			ans += right - left + 1;
			++right;
		}
		return ans;
	}
};

int main(void)
{
	vector<int> vec{10,5,2,6};
	Solution s;
	cout << s.numSubarrayProductLessThanK(vec, 100) << endl;
	return 0;
}
