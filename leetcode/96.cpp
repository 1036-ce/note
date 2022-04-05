// url: https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/

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
	int maxDepth(TreeNode* root) {
		if (!root) 
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

int main(void)
{
	
	return 0;
}
