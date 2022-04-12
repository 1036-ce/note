// url: https://leetcode-cn.com/problems/jump-game/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int ans = true;
		int pos = n - 1;
		for (int i = n - 2; i >= 0; --i) {
			if (i + nums[i] >= pos) {
				ans = true;
				pos = i;
			}
			else
				ans = false;
		}
		return ans;
	}
};

int main(void)
{
	vector<int> nums{2,5,0,0};
	Solution s;
	cout << s.canJump(nums) << endl;
	return 0;
}
