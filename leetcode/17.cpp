// url: https://leetcode-cn.com/problems/min-cost-climbing-stairs/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int dp[1010] = {0};
		dp[0] = 0, dp[1] = 0;
		int size = cost.size();
		for (int i = 2; i <= size; ++i) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[size];
	}
};

int main(void)
{
	vector<int> vec{10, 15, 20};
	Solution s;
	cout << s.minCostClimbingStairs(vec) << endl;
	return 0;
}
