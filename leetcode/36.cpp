// url: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0, head);	// 哑节点，使不必对头指针特殊判断
		ListNode *p1 = dummy, *p2 = dummy;

		while (n--)
			p2 = p2->next;
		while (p2->next) {
			p1 = p1->next;
			p2 = p2->next;
		}
		ListNode *tmp = p1->next;
		p1->next = p1->next->next;
		delete tmp;
		head = dummy->next;
		delete dummy;
		return head;
	}
};

int main(void)
{
	return 0;
}
