// url: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/

#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
	Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
	Node(int _val, Node* _left, Node* _right, Node* _next) :
		val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	// node->left->next = node->right,
	// node->right->next = node->next->left;
	Node* connect(Node* root) {
		if (!root) 
			return nullptr;
		Node *ans = root;
		while (root->left) {
			Node *tmp = root;
			while (root) {
				root->left->next = root->right;
				if (root->next)
					root->right->next = root->next->left;
				root = root->next;
			}
			root = tmp->left;
		}
		return ans;
	}	

	/* Node* eval(Node* root) {
	 *     if (!root) return nullptr;
	 *     if (root->left && root->right) {
	 *         root->left->next = root->right;
	 *         root->right->next = eval(root->next);
	 *         eval(root->left);
	 *         return root->left;
	 *     }
	 *     else
	 *         return nullptr;
	 * } */
};

int main(void)
{

	return 0;
}
