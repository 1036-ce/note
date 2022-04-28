// url: https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	// int cnt = 0;
	int dfs(int n, int val) {
		if (n == 1) {
			if (val >= 1 && val <= 6)
				return 1;
			else
				return 0;
		}
		int ans = 0;
		for (int i = 1; i <= 6; ++i) {
			ans += dfs(n - 1, val - i);
		}
		return ans;
	}
	vector<double> dicesProbability(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1));
		dp[1].assign(7, 1);
		for (int i = 2; i <= n; ++i) {
			for (int j = i; j <= 6 * i; ++j) {
				for (int val = 1; val <= 6; ++val) {
					if (j - val < 1)
						dp[i][j] += 0;
					else
						dp[i][j] += dp[i - 1][j - val];
				}
			}
		}
		vector<double> ans;
		double down = pow(6, n);
		for (int i = n; i <= 6 * n; ++i) {
			// ans.push_back(dfs(n, i) / down);
			ans.push_back(dp[n][i] / down);
		}
		return ans;
	}
};

int main(void)
{
	Solution s;
	auto ans = s.dicesProbability(1);
	for (auto i: ans)
		cout << i << ' ';
	cout << endl;
	return 0;
}
