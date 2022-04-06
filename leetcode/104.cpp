// url: https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode *p, TreeNode *q) {
		if (root == nullptr || root == p || root == q)
			return root;

		TreeNode *l = lowestCommonAncestor(root->left, p, q);
		TreeNode *r = lowestCommonAncestor(root->right, p, q);

		if (l && r)		return root;
		if (!l && r)	return r;
		if (l && !r)	return l;
		return nullptr;
	}
};

int main(void)
{
	TreeNode *root = new TreeNode(6);
	root->left = new TreeNode(2);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);
	root->left->right->right = new TreeNode(5);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);
	TreeNode *p = root->left;
	TreeNode *q = root->right;
	Solution s;
	auto ans = s.lowestCommonAncestor(root, p, q);
	cout << ans->val << endl;
	return 0;
}
