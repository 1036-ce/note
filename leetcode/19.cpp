// url: https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/

#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

class Solution {
public:
	string reverseLeftWords(string &s, int n) {
		int size = s.size(), i = 0, j = size - 1;
		n %= size;
		if (!n) return s;
		while (i < j) {
			std::swap(s[i], s[j]);
			++i, --j;
		}

		i = 0, j = size - n - 1;
		while (i < j) {
			std::swap(s[i], s[j]);
			++i, --j;
		}

		i = size - n, j = size - 1;
		while (i < j) {
			std::swap(s[i], s[j]);
			++i, --j;
		}
		return s;
	}
};

int main(void)
{
	string s1("lrloseumgh");
	Solution s;
	cout << s.reverseLeftWords(s1, 6) << endl;
	return 0;
}
