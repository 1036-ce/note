// url: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

#include <ios>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int arr[300];
		int ret = 0;
		int size = s.size();
		memset(arr, -1, sizeof(int) * 300);
		int l = 0, r = 0;

		while (r != size) {
			char c = s[r];
			l = max(l, arr[c] + 1);
			ret = max(ret, r - l + 1);
			arr[c] = r;
			++r;
		}
		return ret;
	}
};

int main(void)
{
	string s("umvejcuuk");
	Solution so;
	cout << so.lengthOfLongestSubstring(s) << endl;
	return 0;
}
