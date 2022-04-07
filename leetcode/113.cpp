// url: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		int n = postorder.size();
		return verify(postorder, 0, n - 1);
	}

	bool verify(vector<int>& postorder, int s, int e) {
		if (s >= e) return true;
		int i;
		for (i = e - 1; i >= s; --i) {
			if (postorder[i] < postorder[e])
				break;
		}
		bool a = verify(postorder, i + 1, e - 1);
		bool b = verify(postorder, s, i);
		for (; i >= s; --i)
			if (postorder[i] >= postorder[e])
				return false;
		return a && b;
	}
};

int main(void)
{
	vector<int> nums{1,3,2,6,5};
	Solution s;
	cout << s.verifyPostorder(nums) << endl;
	return 0;
}
