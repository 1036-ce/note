// url: https://leetcode-cn.com/problems/merge-two-binary-trees/

#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		TreeNode *ans;
		if (root1 && root2) {
			root1->val += root2->val;
			ans = root1;
		}
		else if (root1 && !root2)
			ans = root1;
		else if (!root1 && root2)
			ans = root2;
		else
			ans = nullptr;
		
		if (ans) {
			TreeNode *r1l = nullptr, *r1r = nullptr, *r2l = nullptr, *r2r = nullptr;
			if (root1) {
				r1l = root1->left;
				r1r = root1->right;
			}
			if (root2) {
				r2l = root2->left;
				r2r = root2->right;
			}
			ans->left = mergeTrees(r1l, r2l);
			ans->right = mergeTrees(r1r, r2r);
		}
		return ans;
	}
};

int main(void)
{
	return 0;
}
