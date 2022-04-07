// url: https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		n = abs(n);
		double ans  = x;
		double num = 1.0;
		while (n != 1) {
			if (n % 2 == 0) {
				ans = ans * ans;
				n /= 2;
			}
			else {
				num *= ans;
				ans = ans * ans;
				n /= 2;
			}
		}
		if (f)
			return ans * num;
		else
			return 1.0 / (ans * num);
	}
};

int main(void)
{
	Solution s;
	cout << s.myPow(2, -2) << endl;
	return 0;
}
