// url: https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isStraight(vector<int>& nums) {
		vector<int> arr(14);
		int left = 15, right = -1;
		int num = 0;
		for (auto i: nums) {
			if (i > 0) {
				++num;
				arr[i] = 1;
				left = min(left, i);
				right = max(right, i);
			}
		}
		if (right - left > 4)
			return false;
		for (int i = left; i <= right; ++i) {
			if (arr[i] == 1)
				--num;
		}
		return !num;
	}
};

int main(void)
{
	
	return 0;
}
