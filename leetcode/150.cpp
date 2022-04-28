// url: https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> ans;
	string tmp;
	vector<int> vis;
	vector<string> permutation(string s) {
		sort(s.begin(), s.end());
		vis.assign(8, 0);
		dfs(s, s.size());
		return ans;
	}

	void dfs(string& s, int cnt) {
		if (cnt == 0) {
			ans.push_back(tmp);
			return;
		}
		int i = 0;
		while (i != s.size()) {
			if (vis[i] == 0) {
				tmp += s[i];
				vis[i] = 1;
				dfs(s, cnt - 1);
				vis[i] = 0;
				tmp.pop_back();
				while (i + 1 != s.size() && s[i] == s[i + 1])
					++i;
			}
			++i;
		}
	}
};

int main(void)
{
	string s("abc");
	Solution s1;
	auto ans = s1.permutation(s);
	for (auto i: ans)
		cout << i << endl;
	return 0;
}
