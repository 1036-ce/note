// url: https://leetcode-cn.com/problems/search-insert-position/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				l = mid + 1;
			else
				r = mid - 1;
		}
		return l;
	}
};

int main(void)
{
	vector<int> nums{1,3,5,6};
	Solution s;
	cout << s.searchInsert(nums, 0) << endl;
	return 0;
}
