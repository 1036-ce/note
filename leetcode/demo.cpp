#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

using namespace std;

class BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n): n(_n), tree(_n + 1) {}

    static int lowbit(int x) {
        return x & (-x);
    }

    int query(int x) {
        int ret = 0;
        while (x) {
            ret += tree[x];
            x   -= lowbit(x);
        }
        return ret;
    }

    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;
        // 离散化
        sort(tmp.begin(), tmp.end());
        for (int& num: nums) {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        }
        // 树状数组统计逆序对
        BIT bit(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans += bit.query(nums[i] - 1);
            bit.update(nums[i]);
        }
        return ans;
    }
};

// code action = quick_fix + refactoring
int main(void) {
	Solution s;
	vector<int> vec{5,5,2,3,6};
	vec.assign(12, 23);
	BIT b(12);

	cout << "asdasd" << endl;
	cout << "asdasd" << endl;
	cout << "asdasd" << endl;
	vector<int> ans;
	ans.push_back(12);
	ans.push_back(12);

	cout << s.reversePairs(vec) << endl;
	return 0;
}
