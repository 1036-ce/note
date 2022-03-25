// url: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/

#include <ios>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode *root) {
		if (!root) return {};
		vector<vector<int>> ans;
		deque<TreeNode*> dq;
		dq.push_back(root);
		int flag = 1;

		while (!dq.empty()) {
			int len = dq.size();
			vector<int> tmp;
			for (int i = 0; i != len; ++i) {
				TreeNode *node = dq.front();
				tmp.push_back(node->val);
				if (node->left)
					dq.push_back(node->left);
				if (node->right)
					dq.push_back(node->right);
				dq.pop_front();
			}
			ans.push_back(tmp);
			if (dq.empty()) break;

			tmp = {};
			len = dq.size();
			for (int i = 0; i != len; ++i) {
				TreeNode *node = dq.back();
				tmp.push_back(node->val);
				if (node->right)
					dq.push_front(node->right);
				if (node->left)
					dq.push_front(node->left);
				dq.pop_back();
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
