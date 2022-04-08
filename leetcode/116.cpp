// url: https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
	int add(int a, int b) {
		while (b != 0) {
			int c = (unsigned(a & b)) << 1;		// 计算每一位相加之后的进位
			a ^= b;								// 计算每一位不进位相加的结果
			b = c;
		}
		return a;
	}
};

int main(void)
{
	Solution s;
	cout << s.add(2,-1) << endl;
	return 0;
}
