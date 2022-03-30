// url: https://leetcode-cn.com/problems/combinations/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> temp;
	vector<vector<int>> combine(int n, int k) {
		dfs(n, k, 1);
		return ans;
	}

	void dfs(int n, int k, int s) {
		if (temp.size() + (n - s + 1) < k)
			return;
		if (temp.size() == k) {
			ans.push_back(temp);
			return;
		}

		temp.push_back(s);
		dfs(n, k, s + 1);
		temp.pop_back();
		dfs(n, k, s + 1);
	}
};

int main(void)
{
	int n = 4, k = 2;
	Solution s;
	auto ans = s.combine(n, k);
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
