// url: https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> printNumbers(int n) {
		int stop = 10;
		int tmp = 1;
		while (n != 1) {
			if (n & 1)
				tmp *= stop;
			stop *= stop;
			n = n >> 1;
		}
		stop = stop * tmp;
		vector<int> ans;
		for (int i = 1; i != stop; ++i)
			ans.push_back(i);
		return ans;
	}
};

int main(void)
{
	Solution s;
	auto ans = s.printNumbers(3);
	return 0;
}
