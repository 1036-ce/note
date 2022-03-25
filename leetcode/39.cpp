// url: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/

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
	vector<int> levelOrder(TreeNode *root) {
		queue<TreeNode*> q;
		vector<int> ans;
		q.push(root);

		while (!q.empty()) {
			TreeNode *node = q.front();
			if (node) {
				ans.push_back(node->val);
				q.push(node->left);
				q.push(node->right);
			}
			q.pop();
		}
		return ans;
	}
};

int main(void)
{
	
	return 0;
}
