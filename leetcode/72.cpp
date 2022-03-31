// url: https://leetcode-cn.com/problems/power-of-two/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// (n & (n - 1)) 将最后一位的 1 置为 0
	// (n & -n) 将最后一位1之前的位全置0
	//
	bool isPowerOfTwo(int n) {
		return n > 0 && (n & (n - 1)) == 0;
		// or
		// return n > 0 && (n & -n) == n;
	}
};

int main(void)
{
	int n = 1;
	Solution s;
	cout << s.isPowerOfTwo(4) << endl;
	return 0;
}
