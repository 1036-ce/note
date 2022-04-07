// url: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int> arr(n);
		// vector<int> dp(n);
		for (int i = 1; i != n; ++i) {
			arr[i] = prices[i] - prices[i - 1];
		}
		int ans = 0;
		for (int i = 1; i != n; ++i) {
			if (arr[i] > 0)
				ans += arr[i];
		}
		return ans;
	}
};

int main(void)
{
	return 0;
}

// 1 2 3  0 2
//  1 1 -3 2
