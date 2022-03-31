// url: https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		istringstream is(s);
		vector<string> tmp;
		string word;
		while (is >> word) {
			tmp.push_back(word);
		}
		string ans;
		for (auto it = tmp.crbegin(); it != tmp.crend(); ++it) {
			ans += *it;
			if (it != tmp.crend() - 1)
				ans.push_back(' ');
		}
		return ans;
	}
};

int main(void)
{
	string s1("  a  good example   ");
	Solution s;
	cout << s.reverseWords(s1) << endl;
	return 0;
}
