// url: https://leetcode-cn.com/problems/maximum-length-of-subarray-with-positive-product/

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		int n = nums.size();
		vector<int> posi(n, 0), nega(n, 0);
		if (nums[0] > 0)
			posi[0] = 1;
		else if (nums[0] < 0)
			nega[0] = 1;
		int ans = posi[0];
		for (int i = 1; i != n; ++i) {
			if (nums[i] > 0) {
				posi[i] = posi[i - 1] + 1;
				if (nega[i - 1] > 0)
					nega[i] = nega[i - 1] + 1;
				else
					nega[i] = 0;
			}
			else if (nums[i] < 0) {
				if (nega[i] > 0 && posi[i - 1] > 0) {
					posi[i] = 0;
					nega[i] = 0;
				}
				else if (nega[i - 1] > 0 && posi[i - 1] == 0) {
					if (i - 1 - nega[i - 1] >= 0)
						posi[i] = nega[i - 1] + posi[i - 1 - nega[i - 1]] + 1;
					else
						posi[i] = nega[i - 1] + 1;
					nega[i] = 0;
				}
				else {
					nega[i] = 1;
					posi[i] = 0;
				}
			}
			else {
				nega[i] = 0;
				posi[i] = 0;
			}
			ans = max(ans, posi[i]);
		}
		for (auto i: posi)
			cout << i << ' ';
		cout << endl;
		for (auto i: nega)
			cout << i << ' ';
		cout << endl;
		return ans;
	}
};

int main(void)
{
	vector<int> num{5,-20,-20,-39,-5,0,0,0,36,-32,0,-7,-10,-7,21,20,-12,-34,26,2};
	Solution s;
	cout << s.getMaxLen(num) << endl;
	return 0;
}
