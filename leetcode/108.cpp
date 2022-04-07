// url: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int num = prices[0];
		int ans = 0;
		for (int i = 1; i != n; ++i) {
			ans = max(ans, prices[i] - num);
			num = min(num, prices[i]);
		}
		return ans;
	}
};

int main(void)
{
	vector<int> nums{7,6,4,3,1};
	Solution s;
	cout << s.maxProfit(nums) << endl;
	return 0;
}
