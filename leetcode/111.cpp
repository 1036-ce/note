// url: https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/

#include <iostream>
#include <type_traits>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 迭代法
/* class Solution {
 * public:
 *     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
 *         if (!preorder.size()) {
 *             return nullptr;
 *         }
 *         TreeNode* root = new TreeNode(preorder[0]);
 *         stack<TreeNode*> stk;
 *         stk.push(root);
 *         int inorderIndex = 0;
 *         for (int i = 1; i < preorder.size(); ++i) {
 *             int preorderVal = preorder[i];
 *             TreeNode* node = stk.top();
 *             if (node->val != inorder[inorderIndex]) {
 *                 node->left = new TreeNode(preorderVal);
 *                 stk.push(node->left);
 *                 cout << "1: " << node->left->val << endl;
 *             }
 *             else {
 *                 while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
 *                     node = stk.top();
 *                     stk.pop();
 *                     ++inorderIndex;
 *                 }
 *                 node->right = new TreeNode(preorderVal);
 *                 stk.push(node->right);
 *                 cout << "2: " << node->right->val << endl;
 *             }
 *         }
 *         return root;
 *     }
 * }; */

// 递归法
/* class Solution {
 * public:
 *     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
 *         int n = preorder.size();
 *         TreeNode *root = build(preorder, inorder, 0, n - 1, 0);
 *         return root;
 *     }
 * 
 *     TreeNode* build(vector<int>& preorder, vector<int>& inorder, int is, int ie, int s) {
 *         if (ie < is)
 *             return nullptr;
 *         TreeNode *root = new TreeNode(preorder[s]);
 *         int m;
 *         for (int i = is; i <= ie; ++i) {
 *             if (inorder[i] == preorder[s]) {
 *                 m = i;
 *                 break;
 *             }
 *         }
 *         root->left = build(preorder, inorder, is, m - 1, s + 1);
 *         root->right = build(preorder, inorder, m + 1, ie, s + m - is + 1);
 *         return root;
 *     }
 * };
 *  */
void transfer(TreeNode *root) {
	if (root) {
		cout << root->val << ' ';
		transfer(root->left);
		transfer(root->right);
	}
}

int main(void)
{
	vector<int> preorder{3,9,8,5,4,10,20,15,7};
	vector<int> inorder{4,5,8,10,9,3,15,20,7};
	Solution s;
	TreeNode *root = s.buildTree(preorder, inorder);
	transfer(root);
	return 0;
}
