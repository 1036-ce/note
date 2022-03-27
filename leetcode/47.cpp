// url: https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1) return 0;
		for (int i = 1; i != n; ++i) {
			prices[i - 1] = prices[i] - prices[i - 1];
		}
		int ans = prices[0], dp = prices[0];
		for (int i = 1; i != n - 1; ++i) {
			dp = prices[i] + max(dp, 0);
			ans = max(ans, dp);
		}
		return ans >= 0 ? ans : 0;
	}
};

int main(void)
{
	vector<int> vec{7,6,4,3,1};
	Solution s;
	cout << s.maxProfit(vec) << endl;
	return 0;
}
