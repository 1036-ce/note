// url: https://leetcode-cn.com/problems/reverse-string/

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int n = s.size(), l = 0, r = n - 1;
		while (l < r) {
			std::swap(s[l], s[r]);
			++l, --r;
		}
	}
};

int main(void)
{
	vector<char> s{'1','2','3'};
	Solution s1;
	s1.reverseString(s);	
	for (auto i: s)
		cout << i << endl;
	return 0;
}
