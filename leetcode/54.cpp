// url: https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	// a = (s[i - 2] - '0') * 10 + (s[i - 1] - '0')
	// if (a >= 10 && a < 26)	dp[i] = dp[i - 1] + dp[i - 2];
	// else						dp[i] = dp[i - 1];
	int translateNum(int num) {
		string s = to_string(num);	
		int n = s.size();
		int l = 1, m = 1, r = 1;
		for (int i = 2; i <= n; ++i) {
			r = m;
			int a = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
			if (a >= 10 && a < 26)
				r += l;
			l = m;
			m = r;
		}
		return r;
		/* int dp[n + 1];
		 * dp[0] = 1, dp[1] = 1;
		 * for (int i = 2; i <= n; ++i) {
		 *     dp[i] = dp[i - 1];
		 *     int a = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
		 *     if (a >= 10 && a < 26)
		 *         dp[i] += dp[i - 2];
		 * }
		 * return dp[n]; */
	}
};

int main(void)
{
	int num = 506;
	Solution s;
	cout << s.translateNum(num) << endl;
	return 0;
}
