// url: https://leetcode-cn.com/problems/jump-game-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	// 贪心
	int jump(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i != n; ++i) 
			nums[i] = i + nums[i];
		int ans = 0;
		int pos = 0;
		while (pos < n - 1) {
			if (nums[pos] >= n - 1)
				return ans + 1;
			int nxt = 0;
			int tmp = 0;
			for (int i = pos + 1; i <= nums[pos]; ++i) {
				if (nums[i] >= tmp) {
					nxt = i;
					tmp = nums[i];
				}
			}
			pos = nxt;
			++ans;
		}
		return ans;
	}
};

int main(void)
{
	vector<int> nums{1,1,1,1};
	Solution s;
	cout << s.jump(nums) << endl;
	return 0;
}
