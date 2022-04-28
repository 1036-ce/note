// url: https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/

#include <algorithm>
#include <cstdlib>
#include <iostream>	
#include <iterator>
#include <locale>
#include <vector>

using namespace std;

// 树状数组求逆序对

class BIT {
public:
	BIT(int _n) : n(_n), tree(_n + 1, 0) {} 
	int query(int x) {
		int ans = 0;
		while (x) {
			ans += tree[x];
			x -= lowbit(x);
		}
		return ans;
	}
	void update(int x) {
		while (x <= n) {
			++tree[x];
			x += lowbit(x);
		}
	}
private:
	int n;
	vector<int> tree;
	int lowbit(int x) {
		return x & -x;
	}
};
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		vector<int> tmp(nums);
		sort(tmp.begin(), tmp.end());
		for (auto& num: nums) 
			num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
		BIT b(n);
		int ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			ans += b.query(nums[i] - 1);
			b.update(nums[i]);
		}
		return ans;
	}
};

// 归并排序求逆序对
/* class Solution {
 * public:
 *     int ans = 0;
 *     void merge_sort(vector<int>& nums, vector<int>& tmp, int s, int e) {
 *         if (e <= s)
 *             return;
 *         int m = s + (e -s) / 2;
 *         merge_sort(nums, tmp, s, m);
 *         merge_sort(nums, tmp, m + 1, e);
 *         int p1 = s, p2 = m + 1;
 *         int pos = s;
 *         while (p1 <= m && p2 <= e) {
 *             if (nums[p1] <= nums[p2])
 *                 tmp[pos++] = nums[p1++];
 *             else {
 *                 tmp[pos++] = nums[p2++];
 *                 ans += m - p1 + 1;
 *             }
 *         }
 *         while (p1 <= m)
 *             tmp[pos++] = nums[p1++];
 *         while (p2 <= e)
 *             tmp[pos++] = nums[p2++];
 *         copy(tmp.begin() + s, tmp.begin() + e + 1, nums.begin() + s);
 *     }
 *     int reversePairs(vector<int>& nums) {
 *         vector<int> tmp(nums.size());
 *         merge_sort(nums, tmp, 0, nums.size() - 1);
 *         for (auto i: nums)
 *             cout << i << ' ';
 *         cout << endl; 
 *         return ans;
 *     }
 * }; */

int main(void)
{
	Solution s;
	// vector<int> nums{7,5,6,4};
	// vector<int> nums{4,5,6,7};
	// vector<int> nums{5,5,2,3,6};
	// vector<int> nums{3,9,5,2,6,1,3};
	// vector<int> nums{1,3,2,3,1};
	vector<int> nums{2,4,3,5,1};
	cout << s.reversePairs(nums) << endl; 
	return 0;
}
