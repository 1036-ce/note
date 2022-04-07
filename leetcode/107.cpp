// url: https://leetcode-cn.com/problems/best-sightseeing-pair/

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& values) {
		int n = values.size();
		int cnt = values[0];
		int ans = 0;
		for (int i = 1; i != n; ++i) {
			ans = max(ans, cnt + values[i] - i);
			cnt = max(cnt, values[i] + i);
		}
		return ans;
	}
};

int main(void)
{
	vector<int> nums{2,2,2};
	Solution s;
	cout << s.maxScoreSightseeingPair(nums) << endl;
	return 0;
}
