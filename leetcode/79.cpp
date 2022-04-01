// url: https://leetcode-cn.com/problems/single-number/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		 int ans = nums[0];
		 int n = nums.size();
		 for (int i = 1; i != n; ++i) {
			 ans ^= nums[i];
		 }
		 return ans;
	}
};

int main(void)
{
	vector<int> nums{4,1,2,1,2};
	Solution s;
	cout << s.singleNumber(nums) << endl;
	return 0;
}
