// url: https://leetcode-cn.com/problems/subtree-of-another-tree/

#include <iostream>
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
		vector <int> sOrder, tOrder;
		int maxElement, lNull, rNull;

		void getMaxElement(TreeNode *o) {
			if (!o) {
				return;
			}
			maxElement = max(maxElement, o->val);
			getMaxElement(o->left);
			getMaxElement(o->right);
		}

		void getDfsOrder(TreeNode *o, vector <int> &tar) {
			if (!o) {
				return;
			}
			tar.push_back(o->val);
			if (o->left) {
				getDfsOrder(o->left, tar);
			} else {
				tar.push_back(lNull);
			}
			if (o->right) {
				getDfsOrder(o->right, tar);
			} else {
				tar.push_back(rNull);
			}
		}

		bool kmp() {
			int sLen = sOrder.size(), tLen = tOrder.size();
			vector <int> fail(tOrder.size(), -1);
			for (int i = 1, j = -1; i < tLen; ++i) {
				while (j != -1 && tOrder[i] != tOrder[j + 1]) {
					j = fail[j];
				}
				if (tOrder[i] == tOrder[j + 1]) {
					++j;
				}
				fail[i] = j;
			}

			for (int i = 0, j = -1; i < sLen; ++i) {
				while (j != -1 && sOrder[i] != tOrder[j + 1]) {
					j = fail[j];
				}
				if (sOrder[i] == tOrder[j + 1]) {
					++j;
				}
				if (j == tLen - 1) {
					return true;
				}
			}
			return false;
		}

		bool isSubtree(TreeNode* s, TreeNode* t) {
			maxElement = INT_MIN;
			getMaxElement(s);
			getMaxElement(t);
			lNull = maxElement + 1;
			rNull = maxElement + 2;

			getDfsOrder(s, sOrder);
			getDfsOrder(t, tOrder);

			return kmp();
		}
};


// 深度优先搜索，暴力匹配
/* class Solution {
 * public:
 *     bool isSubtree(TreeNode *root, TreeNode *subRoot) {
 *         if (!root)
 *             return false;
 *         bool ans;
 *         if (root->val == subRoot->val)
 *             ans = same(root, subRoot);
 *         return ans || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
 *     }
 *     
 *     bool same(TreeNode *root, TreeNode *subRoot) {
 *         if (!root && !subRoot)
 *             return true;
 *         if (!root || !subRoot)
 *             return false;
 *         if (root->val != subRoot->val)
 *             return false;
 *         return same(root->left, subRoot->left) && same(root->right, subRoot->right);
 *     }
 * };
 *  */
int main(void)
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(1);
	TreeNode *sub = new TreeNode(1);
	Solution s;
	cout << s.isSubtree(root, sub) << endl;
	return 0;
}
