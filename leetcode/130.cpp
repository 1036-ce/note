// url: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// 动态规划
	/* int maxProfit(vector<int>& prices, int fee) {
	 *     int n = prices.size();
	 *     int buy = -prices[0], sell = 0;
	 *     for (int i = 1; i != n; ++i) {
	 *         tie()
	 *         int tmp = buy;
	 *         buy = max(buy, sell - prices[i]);
	 *         sell = max(sell, tmp + prices[i] - fee);
	 *     }
	 *     return sell;
	 * } */

	// 贪心
	/* int maxProfit(vector<int> prices, int fee) {
	 *     int buy = prices[0] + fee;
	 *     int n = prices.size();
	 *     int ans = 0;
	 *     for (int i = 1; i != n; ++i) {
	 *         if (prices[i] + fee < buy)
	 *             buy = prices[i] + fee;
	 *         else if (prices[i] > buy) {
	 *             ans += prices[i] - buy;
	 *             buy = prices[i];
	 *         }
	 *     }
	 *     return ans;
	 * } */
};

int main(void)
{
	vector<int> nums{1,3,2,8,4,9};
	// vector<int> nums{1,3,7,5,10,3};
	// vector<int> nums{9,8,7,1,2};
	// vector<int> nums{1,4,6,2,8,3,10,14};
	Solution s;
	cout << s.maxProfit(nums, 2) << endl;
	return 0;
}
