// url: https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/

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
	bool isSubStructure(TreeNode *A, TreeNode *B) {
		if (!B)
			return false;
		queue<TreeNode*> q;
		q.push(A);
		bool ans = false;
		
		while (!q.empty()) {
			TreeNode *node = q.front();
			if (node->val == B->val)
				ans = ans || isSub(node, B);
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
			q.pop();
		}
		return ans;
	}

	bool isSub(TreeNode *A, TreeNode *B) {
		if (!B)
			return true;
		if (!A)
			return false;
		if (A->val != B->val)
			return false;

		return isSub(A->left, B->left) && isSub(A->right, B->right);
	}
};

int main(void)
{
	
	return 0;
}
