// url: https://leetcode-cn.com/problems/jian-sheng-zi-lcof/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 3)
			return n - 1;
		int b = n % 3;
		int a = n / 3;
		if (b == 0) return pow(3, a);
		if (b == 1) return pow(3, a - 1) * 4;
		if (b == 2)	return pow(3, a) * 2;
		return 0;
	}
};

int main(void)
{
	Solution s;
	cout << s.cuttingRope(10) << endl;
	return 0;
}
