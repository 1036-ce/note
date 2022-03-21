// url: https://leetcode-cn.com/problems/move-zeroes/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int size = nums.size();
		int i = 0, j = 0;
		while (j < size) {
			if (nums[j]) {
				std::swap(nums[i], nums[j]);
				++i;
			}
			++j;
		}
	}
};

int main(void)
{
	vector<int> vec{0};

	Solution s;
	s.moveZeroes(vec);
	for (auto i: vec) 
		cout << i << endl;
	return 0;
}
