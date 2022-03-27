// url: https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/

#include <ios>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool issame(TreeNode *l, TreeNode *r) {
		if (!l && !r)
			return true;
		if (!l || !r || l->val != r->val)
			return false;
		/* if ((l && !r) || (!l && r))
		 *     return false;
		 * if (l->val != r->val)
		 *     return false; */
		return issame(l->left, r->right) && issame(l->right, r->left);
	}
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return issame(root->left, root->right);
	}
};

int main(void)
{
	
	return 0;
}
