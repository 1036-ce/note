// url: https://leetcode-cn.com/problems/fibonacci-number/

#include <iostream>

using namespace std;

class Solution {
public:
	int fib(int n) {
		if (n == 0) return 0;
		int l = 0, m = 1, r = 1;
		int cnt = 1;
		while (cnt < n) {
			r = l + m;
			l = m;
			m = r;
			++cnt;
		}
		return r;
	}
};

int main(void)
{
	Solution s;
	cout << s.fib(7) << endl;
	return 0;
}
