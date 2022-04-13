// url: https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		int n = s.size();
		string pattern("eE");
		auto it = s.begin();
		while (*it == ' ') {
			s.erase(it);
			it = s.begin();
		}
		it = s.end() - 1;
		while (*it == ' ') {
			s.erase(it);
			it = s.end() - 1;
		}
		/* stringstream is(s);
		 * is >> s; */
		auto pos = s.find_first_of(pattern);
		if (pos == string::npos)
			return isInteger(s) || isDecimal(s);
		else {
			string left = s.substr(0, pos);
			string right = s.substr(pos + 1, s.size() - pos);
			return (isInteger(left) || isDecimal(left)) && isInteger(right);
		}
	}

	bool isInteger(string s) {
		int n = s.size();
		if (n == 0)
			return false;
		// if (s[0] == '+' || s[0] == '-' || isdigit(s[0]))
		if (s[0] != '+' && s[0] != '-' && !isdigit(s[0]))
			return false;
		if ((s[0] == '+' || s[0] == '-') && n == 1)
			return false;
		int i = 1;
		while (i != n) {
			if (!isdigit(s[i]))
				return false;
			++i;
		}
		return true;
	}

	bool isDecimal(string s) {
		int n = s.size();
		if (s[0] == '+' || s[0] == '-')
			s = s.substr(1, n - 1);
		auto pos = s.find_first_of(".");
		if (pos == string::npos)
			return false;
		string left = s.substr(0, pos);
		string right = s.substr(pos + 1, n - pos);
		if (left[0] == '+' || left[0] == '-')
		    return false; 
		if (right[0] == '+' || right[0] == '-')
			return false;
		if (left.empty())
			return isInteger(right);
		if (right.empty())
			return isInteger(left);
		return isInteger(left) && isInteger(right);
	}
};

int main(void)
{
	string s(".-4");
	Solution s1;
	cout << s1.isNumber(s) << endl;
	return 0;
}
