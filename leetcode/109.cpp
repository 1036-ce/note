// url: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <iostream>
#include <locale>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int> arr(n);
		for (int i = 1; i != n; ++i)
			arr[i] = prices[i] - prices[i - 1];
		int ans = 0;
		for (int i = 1; i != n; ++i)
			if (arr[i] > 0)
				ans += arr[i];
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
