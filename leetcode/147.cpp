// url: https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0) return {};
		deque<int> dq;
		vector<int> ans;
		for (int i = 0; i != k; ++i) {
			while (!dq.empty() && nums[i] >= nums[dq.back()])
				dq.pop_back();
			dq.push_back(i);
		}
		ans.push_back(nums[dq.front()]);
		for (int i = k; i != n; ++i) {
			while (!dq.empty() && nums[i] >= nums[dq.back()])
				dq.pop_back();
			dq.push_back(i);
			if (dq.front() <= i - k)
				dq.pop_front();
			ans.push_back(nums[dq.front()]);
		}
		return ans;
	}
};

int main(void)
{
	Solution s;
	vector<int> nums{1,3,-1,-3,5,3,6,7};
	// vector<int> nums{1,3,1,2,0,5};
	auto ans = s.maxSlidingWindow(nums, 3);
	for (auto i: ans)
		cout << i << ' ';

	return 0;
}
