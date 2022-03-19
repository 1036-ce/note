// url: https://leetcode-cn.com/problems/construct-string-from-binary-tree/

#include <iostream>
#include <string>
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
	string res;
	string tree2str(TreeNode *root) {
		dfs(root);
		return res;
	}

	void dfs(TreeNode *root) {
		if (!root) return;
		res += to_string(root->val);
		if (!root->left && !root->right) return;
		res += '(';
		dfs(root->left);
		res += ')';
		if (root->right) {
			res += '(';
			dfs(root->right);
			res += ')';
		}
	}
};

int main(void)
{
	
	return 0;
}
