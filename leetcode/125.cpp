// url: https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// 摩尔投票法,找出占比一半以上的元素值
	int majorityElement(vector<int>& nums) {
		int ans = 0, f = 0;		// f为当前得票数，ans为当前的暂时获胜者
		int n = nums.size();
		for (int i = 0; i != n; ++i) {
			if (f == 0) {		// 当前得票数为0，选择一个新的获胜者
				ans = nums[i];
				f = 1;
			}
			else if (ans == nums[i])	// 当前值与ans相同，得票数加1
				++f;
			else						// 当前值与ans不同，得票数减1
				--f;
		}
		return ans;
	}
};

int main(void)
{
	
	return 0;
}
