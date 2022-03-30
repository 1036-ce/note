// url: https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/


#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		if (n == 0) return 0;
		int arr[300];
		memset(arr, -1, sizeof(int) * 300);
		int l = 0, r = 0;
		int ans = 0;

		for (; r != n; ++r) {
			if (arr[s[r]] >= l)
				l = arr[s[r]] + 1;
			arr[s[r]] = r;
			ans = max(ans, r - l + 1);
		}
		return ans;
	}
};

int main(void)
{
	string s1("abcabcbb");
	Solution s;
	cout << s.lengthOfLongestSubstring(s1) << endl;
	return 0;
}
