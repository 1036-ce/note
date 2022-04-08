// url: https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ans = 0;
		while (n) {
			n = n & (n - 1);
			++ans;
		}
		return ans;
	}
}

int main(void)
{
	
	return 0;
}
