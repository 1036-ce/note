// url: https://leetcode-cn.com/problems/n-th-tribonacci-number/

#include <iostream>

using namespace std;

class Solution {
public:
	int tribonacci(int n) {
		if (n == 0) return 0;
		int l = 0, m = 1, r = 1, ret = 1;
		int cnt = 2;

		while (cnt < n) {
			ret = l + m + r;
			l = m;
			m = r;
			r = ret;
			++cnt;
		}
		return ret;
	}
}

int main(void)
{
	
	return 0;
}
