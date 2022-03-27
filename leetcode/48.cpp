// url: https://leetcode-cn.com/problems/permutation-in-string/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int n = s1.size(), m = s2.size();
		if (n > m) return false;

		int arr[26] ;
		memset(arr, 0 ,sizeof(arr));
		for (int i = 0; i != n; ++i)
			++arr[s1[i] - 'a'];
		int l = 0;
		for (int r = 0; r != m; ++r) {
			--arr[s2[r] - 'a'];

			/* here is the key */
			while (arr[s2[r] - 'a'] < 0) {
				++arr[s2[l] - 'a'];
				++l;
			}

			if (r - l + 1 == n)
				return true;
		}
		return false;
	}
};

int main(void)
{
	string s1("adc"), s2("dcda");
	Solution s;
	cout << s.checkInclusion(s1, s2) << endl;
	return 0;
}
