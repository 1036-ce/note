// url: https://leetcode-cn.com/problems/letter-case-permutation/

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> ans;
	vector<string> letterCasePermutation(string s) {
		dfs(s, 0);
		return ans;
	}

	void dfs(string s, int cur) {
		if (cur == s.size()) {
			ans.push_back(s);
			return;
		}

		if (isalpha(s[cur])) {
			s[cur] = tolower(s[cur]);
			dfs(s, cur + 1);
			s[cur] = toupper(s[cur]);
			dfs(s, cur + 1);
		}
		else {
			dfs(s, cur + 1);
		}
	}
};

int main(void)
{
	string s1("3z4");
	Solution s;
	auto ans = s.letterCasePermutation(s1);
	for (auto i : ans) {
		cout << i << endl;
	}
	return 0;
}
