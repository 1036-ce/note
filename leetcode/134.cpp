// url: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<char>> m;
	vector<string> ans;
	string tmp;
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return ans;
		m.assign({
				{},
				{},
				{'a','b','c'},
				{'d','e','f'},
				{'g','h','i'},
				{'j','k','l'},
				{'m','n','o'},
				{'p','q','r','s'},
				{'t','u','v'},
				{'w','x','y','z'}
				});
		dfs(digits, 0);
		return ans;
	}

	void dfs(string& digits, int s) {
		if (s == digits.size()) {
			ans.push_back(tmp);
			return;
		}
		int c = digits[s] - '0';
		for (auto i: m[c]) {
			tmp += i;
			dfs(digits, s + 1);
			tmp.pop_back();
		}
	}
};

int main(void)
{
	Solution s;
	auto ans = s.letterCombinations("");
	for (auto c: ans)
		cout << c << endl;
	return 0;
}
