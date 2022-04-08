// url: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/

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
	Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), 
							right(_right), next(_next) {}
};

class Solution {
public:
	Node* connect(Node* root) {
		Node *ans = root;
		while (root) {
			Node *cur = root;
			Node *l = nullptr, *r = nullptr;
			while (cur) {
				l = cur->left;
				if (l)	break;
				l = cur->right;
				if (l)	break;
				cur = cur->next;
			}
			root = l;
			while (cur) {
				r = cur->left;
				if (l != r && r) {
					l->next = r;
					l = r;
				}
				r = cur->right;
				if (l != r && r) {
					l->next = r;
					l = r;
				}
				cur = cur->next;
			}
		}
		return ans;
	}
};

int main(void)
{
	
	return 0;
}
