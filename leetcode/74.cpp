// url: https://leetcode-cn.com/problems/maximum-product-subarray/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// fmax[i] = max(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i], nums[i])
// fmin[i] = min(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i], nums[i])
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		vector<int> fmax(n), fmin(n);
		int ans = nums[0];
		fmax[0] = nums[0], fmin[0] = nums[0];
		for (int i = 1; i != n; ++i) {
			fmax[i] = tmax(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i], nums[i]);
			fmin[i] = tmin(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i], nums[i]);
			ans = max(ans, fmax[i]);
		}
		return ans;
		// return *max_element(fmax.begin(), fmax.end());
	}
private:
	int tmin(int a, int b, int c) {
		int ans = min(a, b);
		ans = min(ans, c);
		return ans;
	}
	int tmax(int a, int b, int c) {
		int ans = max(a, b);
		ans = max(ans, c);
		return ans;
	}
};

int main(void)
{
	vector<int> nums{-2, -2, -3};
	Solution s;
	cout << s.maxProduct(nums) << endl;
	return 0;
}
