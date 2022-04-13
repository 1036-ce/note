// url: https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/

#include <cctype>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
	int strToInt(string str) {
		auto it = str.begin();
		while (*it == ' ') {
			str.erase(it);
			it = str.begin();
		}
		int f = 1;
		if (*it == '-') {
			f = -1;
			++it;
		}
		else if (*it == '+')
			++it;
		long long ans = 0;
		while (it != str.end()) {
			if (isdigit(*it)) {
				ans *= 10;
				ans += *it - '0';
				if (ans > INT_MAX) {
					if (f == -1)
						return INT_MIN;
					else
						return INT_MAX;
				}
				++it;
			}
			else
				break;
		}
		return (int)(ans * f);
	}
};

int main(void)
{
	string s("-91283472332");
	Solution s1;
	cout << s1.strToInt(s) << endl;
	return 0;
}
