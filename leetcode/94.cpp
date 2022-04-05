// url: https://leetcode-cn.com/problems/backspace-string-compare/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool backspaceCompare(string s, string t) {
		string n, m;
		int len1 = s.size(), len2 = t.size();
		for (int i = 0; i != len1; ++i) {
			if (s[i] == '#') {
				if (!n.empty())
					n.pop_back();
			}
			else
				n.push_back(s[i]);
		}
		for (int i = 0; i != len2; ++i) {
			if (t[i] == '#') {
				if (!m.empty())
					m.pop_back();
			}
			else
				m.push_back(t[i]);
		}
		return n == m;
	}
};

int main(void)
{
	string s("y#fo##f"), t("y#f#o##f");
	Solution s1;
	cout << s1.backspaceCompare(s, t) << endl;
	return 0;
}
