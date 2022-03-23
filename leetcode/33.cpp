// url: https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int n = numbers.size(), l = 0, r = n - 1;
		while (l < r) {
			int m = l + (r - l) / 2;

			// number[m] == number[r] 时，number[r] 一定不是最小值, --r;
			if (numbers[m] == numbers[r])		
				--r;
			else if (numbers[m] > numbers[r])
				l = m + 1;
			else 
				r = m;
		}
		return numbers[l];
	}
};

int main(void)
{
	vector<int> vec{10,1,10,10,10};
	Solution s;
	cout << s.minArray(vec) << endl;
	return 0;
}
