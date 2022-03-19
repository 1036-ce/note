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
		pair<int, int> arr[300];
		int ret = 0;
		int last = 0;
		int pre = 0;
		int size = s.size();
		int cur = 0;
		memset(arr, -1, sizeof(pair<int, int>) * 300);
		for (int i = 0; i != size; ++i) {
			char c = s[i];
			if (arr[c].first != -1) {
				arr[c].second = max(arr[c].second, i - arr[c].first);
				last = arr[c].first + 1;
				if (!pre)
					pre = i;
			}
			if (cur < arr[c].first)
				ret = max(ret, arr[c].second);
			if (arr[c].first != -1)
				cur = arr[c].first;
			arr[c].first = i;
		}
		ret = max(ret, size - last);
		ret = max(ret, pre);
		return ret;
	}
};

int main(void)
{
	string s("abba");
	Solution so;
	cout << so.lengthOfLongestSubstring(s) << endl;
	return 0;
}
