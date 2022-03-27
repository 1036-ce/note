// url: https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/

#include <iostream>

using namespace std;

class Solution {
public:
	int numWays(int n) {
		if (n == 0) return 1;
		const int mod = 1e9 + 7;
		int l = 0, m = 1, r = 1;

		for (int i = 0; i != n; ++i) {
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
	cout << s.numWays(0) << endl;
	return 0;
}
