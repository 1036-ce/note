// url: https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/

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
	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		int h1 = height(root->left);
		int h2 = height(root->right);
		int num = abs(h1 - h2);
		return num <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}

	int height(TreeNode *root) {
		if (!root)
			return 0;
		return max(height(root->left), height(root->right)) + 1;
	}
};

int main(void)
{
	
	return 0;
}
