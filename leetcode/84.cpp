// url: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Node {
public:
	int val;
	Node *left;
	Node *right;

	Node() {}
	Node(int _val) {
		val = _val;
		left = nullptr;
		right = nullptr;
	}

	Node(int _val, Node* _left, Node *_right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

class Solution {
public:
	Node* treeToDoublyList(Node* root) {
		auto [pre, nxt] = exec(root);
		if (!pre && !nxt)
			return root;
		else if (pre && !nxt)
			nxt = root;
		else if (!pre && nxt)
			pre = root;

		pre->left = nxt;
		nxt->right = pre; 
		return pre;
	}

	pair<Node*, Node*> exec(Node *root) {
		if (!root)
			return {nullptr, nullptr};
		if (!root->left && !root->right)
			return {root, root};
		auto [p1, n1] = exec(root->left);
		auto [p2, n2] = exec(root->right);
		if (n1) {
			root->left = n1;
			n1->right = root;
		}
		if(p2) {
			root->right = p2;
			p2->left = root;
		}
		if (!p1) p1 = root;
		if (!n2) n2 = root;
		return {p1, n2};
	}
};

int main(void)
{
	/* Node *root = new Node(4);
	 * root->left = new Node(2);
	 * root->right = new Node(5);
	 * root->left->left = new Node(1);
	 * root->left->right = new Node(3); */
	Node *root = new Node(8);
	root->left = new Node(-6);
	root->left->left = new Node(-8);
	Solution s;
	Node *ans = s.treeToDoublyList(root);
	Node *tmp = ans;
	while (ans) {
		cout << ans->val << ' ';
		ans = ans->right;
		if (ans == tmp)
		    break; 
	}
	return 0;
}
