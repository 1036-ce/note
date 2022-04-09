// url: https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/

#include <iostream>
#include <vector>

using namespace std;

// 异或运算的性质：
// 		x ^ 0 = x,	x ^ 1 = ~x
// 与运算的性质:
// 		x & 0 = 0,	x & 1 = x
// 或运算的性质：
// 		x | 0 = x,	x | 1 = 1
//
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0;
		for (int num: nums) {
			ones = ones ^ num & ~twos;
			twos = twos ^ num & ~ones;
		}
		return ones;
	}
};

int main(void)
{
	return 0;
}
