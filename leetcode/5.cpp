// url: https://leetcode-cn.com/problems/binary-search/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int> nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				l = mid + 1;
			else
				r = mid - 1;
		}
		return -1;
	}
};

int main(void)
{
	vector<int> nums{-1, 0, 3, 5, 9, 12};
	Solution s;
	int ret = s.search(nums, 9);
	cout << ret << endl;
	return 0;
}
