// url: https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	// f(n, m) 表示结果所在的下标，而不是结果的值
	//
	// 递归版本
	/* int f(int n, int m) {
	 *     if (n == 1)
	 *         return 0;
	 *     int x = f (n - 1, m);
	 *     return (m + x) % n;
	 * }
	 * int lastRemaining(int n, int m) {
	 *     return f(n, m);
	 * } */

	// 迭代版本
	int lastRemaining(int n, int m) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans = (m + ans) % i;
		}
		return ans;
	}
};

int main(void)
{
	Solution s;
	cout << s.lastRemaining(5, 3) << endl;
	return 0;
}
