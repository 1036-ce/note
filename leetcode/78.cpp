// url: https://leetcode-cn.com/problems/reverse-bits/

#include <cstdint>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		n = (n >> 1) & M1 | (n & M1) << 1;
		n = (n >> 2) & M2 | (n & M2) << 2;
		n = (n >> 4) & M4 | (n & M4) << 4;
		n = (n >> 8) & M8 | (n & M8) << 8;
		return n >> 16 | n << 16;
	}
private:
	const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

	/* uint32_t reverseBits(uint32_t n) {
	 *     bitset<32> num(n);
	 *     string s = num.to_string();
	 *     reverse(s.begin(), s.end());
	 *     bitset<32> ans(s);
	 *     cout << ans.to_string() << endl;
	 *     return ans.to_ulong();
	 * } */
};

int main(void)
{
	bitset<32> num("00000010100101000001111010011100");
	Solution s;
	cout << s.reverseBits(num.to_ulong()) << endl;
	return 0;
}
