// url: https://leetcode-cn.com/problems/powx-n/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double myPow(double x, long long n) {
		if (n == 0) return 1;
		if (n < 0) {
			x = 1.0 / x;
			n = -n;
		}
		double tmp = 1;
		while (n > 1) {
			if (n & 1)
				tmp *= x;
			x *= x;
			n = n >> 1;
		}
		return x * tmp;
	}
};

int main(void)
{
	Solution s;
	cout << s.myPow(2, 1) << endl;
	return 0;
}
