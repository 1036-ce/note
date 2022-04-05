// url: https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 在为两个数字位数相同的情况下，他们的字符串比较结果与两个数的直接比较结果相同
//
class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> vec;
		int n = nums.size();
		for (int i = 0; i != n; ++i)
			vec.push_back(to_string(nums[i]));
		sort(vec.begin(), vec.end(), [](string a, string b) 
										{ return (a + b) < (b + a);});
		string ans;
		for (int i = 0; i != n; ++i)
			ans += vec[i];
		return ans;
	}
};

int main(void)
{
	vector<int> vec{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	Solution s;
	cout << s.minNumber(vec) << endl;
	return 0;
}
