// url: https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size(), l = 0, r = n - 1;
		int m = l + (r - l) / 2;
		while (l < r) {
			if (nums[m] == m)
				l = m + 1;
			else
				r = m;
			m = l + (r - l) / 2;
		}
		if (m == 0 && nums[m] == 0)
			m = 1;
		if (m == n - 1 && nums[m] == n - 1)
			m = n;
		return m;
	}
};

int main(void)
{
	vector<int> vec{1};
	Solution s;
	cout << s.missingNumber(vec) << endl;
	return 0;
}
