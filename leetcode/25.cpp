// url: https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int n = nums.size(), i = 0;
		while (i != n) {
			if (i == nums[i]) {
				++i;
				continue;
			}
			if (nums[nums[i]] == nums[i])
				return nums[i];
			else
				std::swap(nums[i], nums[nums[i]]);
		}
		return -1;
	}
};

int main(void)
{
	vector<int> nums{2,3,1,0,2,5,3};
	Solution s;
	cout << s.findRepeatNumber(nums) << endl;
	return 0;
}
