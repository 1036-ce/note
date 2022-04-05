// url: https://leetcode-cn.com/problems/container-with-most-water/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size(), l = 0, r = n - 1;
		int ans = -1;
		while (l < r) {
			if (height[l] < height[r]) {
				ans = max(ans, height[l] * (r - l));
				++l;
			}
			else {
				ans = max(ans, height[r] * (r - l));
				--r;
			}
		}
		return ans;
	}
};

int main(void)
{
	vector<int> nums{1,1};
	Solution s;
	cout << s.maxArea(nums) << endl;
	return 0;
}
