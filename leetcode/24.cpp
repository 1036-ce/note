// url: https://leetcode-cn.com/problems/delete-and-earn/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		int maxVal = 0;
		for (auto i: nums) 
			maxVal = max(maxVal, i);
		vector<int> sum(maxVal + 1);
		for (auto i: nums)
			sum[i] += i;

		int l = 0, m = sum[0], r = sum[0];
		for (int i = 1; i < maxVal + 1; ++i) {
			r = max(m, l + sum[i]);
			l = m;
			m = r;
		}
		return r;
	}
};

int main(void)
{
	vector<int> vec{2,2,3,3,3,4};
	Solution s;
	cout << s.deleteAndEarn(vec) << endl;
	return 0;
}
