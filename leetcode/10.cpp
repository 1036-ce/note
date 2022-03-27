// url: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

#include <ios>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

iclass Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int arr[300];
		memset(arr, -1, sizeof(int) * 300);
		int i = 0, j = 0, ans = 0;
		int n = s.size();

		for (; j < n; ++j) {
			if (arr[s[j]] >= i)
				i = arr[s[j]] + 1;
			arr[s[j]] = j;
			ans = max(ans, j - i + 1);
		}
		return ans;
	}
};

nt main(void)
{
	string s("umvejcuuk");
	Solution so;
	cout << so.lengthOfLongestSubstring(s) << endl;
	return 0;
}
