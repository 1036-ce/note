// url: https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/

#include <iostream>

using namespace std;

class Solution {
public:
	int fib(int n) {
		if (n == 0) return 0;
		int mod = 1e9 + 7;
		int l = 0, m = 1, r = 1;
		for (int i = 1; i != n; ++i) {
			r = (l + m) % mod;
			l = m;
			m = r;
		}
		return r % mod;
	}
};

int main(void)
{
	Solution s;
	cout << s.fib(4) << endl;
	return 0;
}
