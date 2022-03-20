// url: https://leetcode-cn.com/problems/rotate-array/

#include <iostream>
#include <sched.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

class Solution {
public:
	// 数组翻转
/*     void rotate(vector<int> &nums, int k) {
 *         int size = nums.size();
 *         k %= size;
 *         if (!k) return;
 *         int i = 0, j = size - 1;
 *         while (i < j) {
 *             swap(nums[i], nums[j]);
 *             ++i, --j;
 *         }
 * 
 *         j = k - 1;
 *         i = 0;
 *         while (i < j) {
 *             swap(nums[i], nums[j]);
 *             ++i, --j;
 *         }
 * 
 *         i = k;
 *         j = size - 1;
 *         while (i < j) {
 *             swap(nums[i], nums[j]);
 *             ++i, --j;
 *         }
 *     } */

	// 环状替换
/*     void rotate(vector<int> &nums, int k) {
 *         int size = nums.size();
 *         k %= size;
 *         if (!k) return;
 *         int cnt = gcd(size, k);
 *         // cout << cnt << endl;
 * 
 *         for (int i = 0; i != cnt; ++i) {
 *             int tmp = nums[i], cur = i;
 *             do {
 *                 cur = (cur + k) % size;
 *                 swap(tmp, nums[cur]);
 *             } while (cur != i);
 *         }
 *     } */
};

int main(void)
{
	vector<int> vec{-1, -100, 3, 99};
	Solution s;
	s.rotate(vec, 2);
	for (auto i: vec)
		cout << i << endl;
	return 0;
}
