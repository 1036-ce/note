// url: https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/


#include <asm-generic/errno-base.h>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) :
		val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> tmp;
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		exec(root, target);
		return ans;
	}

	void exec(TreeNode *root, int target) {
		if (!root)
			return;
		if (!root->left && !root->right) {
			if (root->val == target) {
				tmp.push_back(root->val);
				ans.push_back(tmp);
				tmp.pop_back();
			}
			return;
		}
		tmp.push_back(root->val);
		exec(root->left, target - root->val);
		exec(root->right, target - root->val);
		tmp.pop_back();
	}
};

int main(void)
{
	
	return 0;
}
