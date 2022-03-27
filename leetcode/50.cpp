// url: https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#define print(dp, m, n) do { \
	for (int i = 0; i != m; ++i) { \
		for (int j = 0; j != n; ++j) \
			os << dp[i][j] << " "; \
		os << endl; \
	} \
	os << endl; \
} while(0)

class Solution {
	public:
		int maxValue(vector<vector<int>>& grid) {
			// ofstream os("log");
			int m = grid.size(), n = grid[0].size();
			int dp[m][n];
			/* for (int i = 0; i != m; ++i)
			 *     for (int j = 0; j != n; ++j)
			 *         dp[i][j] = 0;  */
			dp[0][0] = grid[0][0];
			for (int i = 1; i != m; ++i)
				dp[i][0] = grid[i][0] + dp[i - 1][0];
			for (int i = 1; i != n; ++i)
				dp[0][i] = grid[0][i] + dp[0][i - 1];

			// print(dp, m, n);
			for (int i = 1; i != m; ++i) {
				for (int j = 1; j != n; ++j) {
					dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
					// print(dp, m, n);
				}
			}
			return dp[m - 1][n - 1];
		}
};

int main(void)
{
	vector<vector<int>> grid{
		{1,2,5},
		{3,2,1}
	};
	Solution s;
	cout << s.maxValue(grid) << endl;
	return 0;
}
