// url: https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int size = numbers.size(), i = 0, j = size - 1;
		while (i < j) {
			if (numbers[i] + numbers[j] == target)
				return {i + 1, j + 1};
			else if (numbers[i] + numbers[j] < target)
				++i;
			else
				--j;
		}
		return {1, 2};
	}
};

int main(void)
{
	vector<int> vec{2,3,4};
	Solution s;
	auto ans = s.twoSum(vec, 6);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}
