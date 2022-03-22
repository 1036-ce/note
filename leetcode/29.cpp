// url: https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		auto l = s.begin(), r = s.begin();
		while (r != s.end()) {
			if (*r == ' ') {
				reverse(l, r);
				l = r + 1;
			}
			++r;
		}
		reverse(l, s.end());
		return s;
	}
};

int main(void)
{
	string s("Let's take Leetcode contest");
	Solution s1;
	s = s1.reverseWords(s);
	cout << s << endl;
	return 0;
}
