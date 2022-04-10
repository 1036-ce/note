// url: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;

		int n = prices.size();
		vector<vector<int>> f(n, vector<int>(3));
		// f[i]表示第i天结束时的状态
		// f[i][0] 表示手中持有股票时的最大利润
		// f[i][1] 表示处于冷静期时的最大利润
		// f[i][2] 表示手中未持有股票时的最大利润
		f[0][0] = -prices[0];
		for (int i = 1; i != n; ++i) {
			f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
			f[i][1] = f[i - 1][0] + prices[i];
			f[i][2] = max(f[i - 1][1], f[i - 1][2]);
		}
		/* for (int i = 0; i != n; ++i) {
		 *     for (int j = 0; j != 3; ++j)
		 *         cout << f[i][j] << '\t';
		 *     cout << endl;
		 * } */
		return max(f[n - 1][1], f[n - 1][2]);
	}
};

int main(void)
{
	// vector<int> nums{2,1,4,5,2,9,7};
	// vector<int> nums{1,4,2,7};
	vector<int> nums{6,1,6,4,3,0,2};
	Solution s;
	cout << s.maxProfit(nums) << endl;
	return 0;
}
