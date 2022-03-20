// url: https://leetcode-cn.com/problems/squares-of-a-sorted-array/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int size = nums.size(), l = 0, r = size - 1;
		vector<int> ret(size);
		while (l <= r) {
			if (nums[l] * nums[l] < nums[r] * nums[r])
				ret[--size] = nums[r] * nums[r--];
			else
				ret[--size] = nums[l] * nums[l++];
		}
		return ret;
	}
};

int main(void)
{
	vector<int> vec{12,3,3,2,12,1};
	Solution s;
	s.sortedSquares(vec);
	return 0;
}
