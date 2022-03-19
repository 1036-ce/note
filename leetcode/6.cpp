// url: https://leetcode-cn.com/problems/first-bad-version/

#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int version)
{
	if (version > 3)
		return true;
	return false;
}

class Solution {
public:
	int firstBadVersion(int n) {
		int l = 0, r = n;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (isBadVersion(mid))
				r = mid;
			else
				l = mid + 1;
		}
		return r;
	}
};

int main(void)
{
	Solution s;
	cout << s.firstBadVersion(8) << endl;
	return 0;
}
