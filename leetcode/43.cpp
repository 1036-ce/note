// url: https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/

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
	TreeNode* mirrorTree(TreeNode *root) {
		if (!root)
			return nullptr;
		TreeNode *ans = new TreeNode(root->val);
		ans->left = mirrorTree(root->right);
		ans->right = mirrorTree(root->left);
		return ans;
	}
};

int main(void)
{
	
	return 0;
}
