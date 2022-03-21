// url: https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		int n = s.size();
		for (int i = 0; i != n; ++i) {
			if (s[i] ==' ') {
				s.replace(i, 1, "%20");
				n += 2;
			}
		}
		return s;
	}
};

int main(void)
{
	string s(" ");
	Solution s1;
	cout << s1.replaceSpace(s) << endl;
	return 0;
}
