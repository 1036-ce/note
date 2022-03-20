/* url: https://leetcode-cn.com/problems/climbing-stairs/ */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		int l = 1, m = 2, r = 2;
		for (int i = 2; i != n; ++i) {
			r = m + l;
			l = m;
			m = r;
		}
		return r;
	}
};

int main(void)
{
	Solution s;
	cout << s.climbStairs(3) << endl;
	return 0;
}
