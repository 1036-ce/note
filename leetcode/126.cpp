// url: https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		if (n == 0) return {};
		if (n == 1) return {1};
		vector<int> left(n), right(n), ans(n);
		left[0] = a[0];
		for (int i = 1; i != n; ++i)
			left[i] = left[i - 1] * a[i];
		right[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; --i)
			right[i]= right[i + 1] * a[i];
		ans[0] = right[1];
		for (int i = 1; i < n - 1; ++i) {
			ans[i] = left[i - 1] * right[i + 1];
		}
		if (n >= 2)
			ans[n - 1] = left[n - 2];
		return ans;
	}
};

int main(void)
{
	vector<int> nums{1,2,3,4,5};
	Solution s;
	auto ans = s.constructArr(nums);
	for (auto i: ans)
		cout << i << ' ';
	return 0;
}
