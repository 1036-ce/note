// url: https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node *random;
	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

void show(Node *l) {
	while (l) {
		cout << l->val << " ";
		l = l->next;
	}
	cout << endl;
}
class Solution {
public:
	Node *copyRandomList(Node *head) {
		if (!head) return nullptr;
		// 链表的复制
		Node *it = head;
		while (it) {
			Node *nxt = it->next;
			it->next = new Node(it->val);
			it->next->next = nxt;
			it = nxt;
		}

		Node *ret = head;
		while (ret) {
			if (ret->random)
				ret->next->random = ret->random->next;
			ret = ret->next->next;
		}

		// 链表的拆分
		Node *tmp = head;
		ret = head->next;
		while (tmp->next) {
			Node *t = tmp->next;
			tmp->next = tmp->next->next;
			tmp = t;
		}
		return ret;
	}
};

int main(void)
{
	Node *head = new Node(1);
	Node *t1 = new Node(2);
	Node *t2 = new Node(3);
	head->next = t1;
	t1->next = t2;
	head->random = t2;
	t1->random = t2;
	t2->random = head;
	Solution s;
	s.copyRandomList(head);

	return 0;
}
