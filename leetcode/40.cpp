// url: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/

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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) return {};
		int len;
		vector<vector<int>> ans;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int len = q.size();
			vector<int> tmp;
			for (int i = 0; i != len; ++i) {
				TreeNode *node = q.front();
				tmp.push_back(node->val);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
				q.pop();
			}
			ans.push_back(tmp);
		}
		return ans;
	}
};

int main(void)
{
	
	return 0;
}
