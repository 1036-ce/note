// url: https://leetcode-cn.com/problems/generate-parentheses/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> ans;
	string tmp;
	vector<string> generateParenthesis(int n) {
		dfs(n, 0, 0);
		return ans;
	}

	void dfs(int n, int left, int right) {
		if (left > n)
			return;
		if (left == right && left == n) {
			ans.push_back(tmp);
			return;
		}
		tmp += '(';
		dfs(n, left + 1, right);
		tmp.pop_back();
		if (left > right) {
			tmp += ')';
			dfs(n, left, right + 1);
			tmp.pop_back();
		}
	}
};

int main(void)
{
	Solution s;
	auto ans = s.generateParenthesis(4) ;
	for (auto i: ans) {
		cout << i << endl;
	}
	return 0;
}
