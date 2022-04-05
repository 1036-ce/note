// url: https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/ 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

iclass Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> arr(26, -1);
		vector<int> ans;
		int len = 0;
		for (auto c: p)
			arr[c - 'a'] = 0;
		for (auto c: p) {
			++len;
			++arr[c - 'a'];
		}

		int n = s.size(), l = 0, r = 0;
		for (; r != n; ++r) {
			if (arr[s[r] - 'a'] > 0) {
				--arr[s[r] - 'a'];
			}
			else {
				while (s[l] != s[r]) {
					if (arr[s[l] - 'a'] != -1)
						++arr[s[l] - 'a'];
					++l;
				}
				++l;
			}
			if (r - l + 1 == len) {
				ans.push_back(l);
			}
		}
		return ans;
	}
};

nt main(void)
{
	string s1("abab");
	Solution s;
	auto ans = s.findAnagrams(s1, "ab");
	for (auto i: ans)
		cout << i << ' ';
	cout << endl;
	return 0;
}
