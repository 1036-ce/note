// url: https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
	char firstUniqChar(string s) {
		int arr[300];
		memset(arr, 0, sizeof(int) * 300);
		for (auto i: s) {
			++arr[i];
		}
		for (int i = 'a'; i <= 'z'; ++i) {
			if (arr[i] == 1)
				return i;
		}
		return ' ';
	}
};

int main(void)
{
	
	return 0;
}
