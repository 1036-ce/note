// url: https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> s;
		int p = 0, n = pushed.size();
		for (int i = 0; i != n; ++i) {
			s.push(pushed[i]);
			while (!s.empty() && s.top() == popped[p]) {
				s.pop();
				++p;
			}
		}
		return p == n;
	}
};

int main(void)
{
	vector<int> pushed{1,2,3,4,5}, poped{4,3,5,1,2};
	Solution s;
	cout << s.validateStackSequences(pushed, poped) << endl;
	return 0;
}
