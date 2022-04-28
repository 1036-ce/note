// url: https://leetcode-cn.com/problems/chou-shu-lcof/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n + 1);
		dp[1] = 1;
		int p2 = 1, p3 = 1, p5 = 1;
		for (int i = 2; i <= n; ++i) {
			dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
			if (dp[i] == dp[p2] * 2)
				++p2;
			if (dp[i] == dp[p3] * 3)
				++p3;
			if (dp[i] == dp[p5] * 5)
				++p5;
		}
		return dp[n];
	}
};

int main(void)
{
	Solution s;
	cout << s.nthUglyNumber(12) << endl;
	return 0;
}
