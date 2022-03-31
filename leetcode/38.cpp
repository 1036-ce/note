// url: https://leetcode-cn.com/problems/maximum-sum-circular-subarray/

#include <deque>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// solution: v2
// 	 max(前置数组 + 后置数组)
// = max(total - 中间剩余数组)
// = total + max(- 中间剩余数组)
// = total - min(中间剩余数组)
class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
		for (int& a : nums) {
			curMax = max(curMax, 0) + a;
			maxSum = max(curMax, maxSum);
			curMin = min(curMin, 0) + a;
			minSum = min(curMin, minSum);
			total += a;
		}
		return maxSum > 0 ? max(maxSum , total - minSum) : maxSum;
	}
}

// solution: v1
/* class Solution {
 * public:
 *     int maxSubarraySumCircular(vector<int>& nums) {
 *         int n = nums.size();
 *         int cur = 0;
 *         int ans = -100000;
 *         for (int i = 0; i != n; ++i) {
 *             cur = nums[i] + max(cur, 0);
 *             ans = max(ans, cur);
 *         }
 * 
 *         int rightsums[n];
 *         rightsums[n - 1] = nums[n - 1];
 *         for (int i = n - 2; i >= 0; --i) {
 *             rightsums[i] = rightsums[i + 1] + nums[i];
 *         }
 * 
 *         int leftsums[n];
 *         leftsums[0] = nums[0];
 *         for (int i = 1; i != n; ++i) {
 *             leftsums[i] = leftsums[i - 1] + nums[i];
 *         }
 * 
 *         int max_right[n];
 *         max_right[n - 1] = rightsums[n - 1];
 *         for (int i = n - 2; i >= 0; --i) {
 *             max_right[i] = max(max_right[i + 1], rightsums[i]);
 *         }
 * 
 *         for (int i = 0; i < n - 2; ++i) {
 *             ans = max(ans, leftsums[i] + max_right[i + 2]);
 *         }
 *         return ans;
 *     }
 * }; */

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		int p[2 * n + 1];
		p[0] = nums[0];
		for (int i = 1; i != 2 * n; ++i) {
			p[i] = p[i - 1] + nums[i % n];
		}

		int ans = nums[0];
		priority_queue<int> q;
		q.push(0);

		for (int j = 1; j < 2 * n; ++j) {
			if (q.top() < j - n)
				q.pop();

			ans = max(ans, p[j] - p[q.top()]);
			q.push(j + 1);
		}
		return ans;
	}
};

int main(void)
{
	vector<int> vec{1,-2,3,-2};
	Solution s;
	cout << s.maxSubarraySumCircular(vec) << endl;
	return 0;
}
