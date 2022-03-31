// url: https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			while (l < r && (nums[l] & 1) == 1) ++l;
			while (l < r && (nums[r] & 1) == 0) --r;
			std::swap(nums[l], nums[r]);
		}
		return nums;
	}
};

int main(void)
{
	vector<int> nums{1,2,3,4};
	Solution s;
	auto ans = s.exchange(nums);
	for (auto i: ans)
		cout << i << " ";
	cout << endl;
	return 0;
}
