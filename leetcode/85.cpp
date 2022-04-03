// url: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/

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
	int kthLargest(TreeNode* root, int k) {
		int s = size(root->right);
		while (s + 1 != k) {
			if (s + 1 < k) {
				root = root->left;
				s = s + 1 + size(root->right);
			}
			else {
				root = root->right;
				s = s - 1 - size(root->left);
			}
		}
		return root->val;
	}

	int size(TreeNode *root) {
		if (!root)
			return 0;
		return size(root->left) + size(root->right) + 1;
	}
};

int main(void)
{
	return 0;
}
