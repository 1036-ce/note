// url: https://leetcode-cn.com/problems/reverse-linked-list/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head)
			return nullptr;
		ListNode *l = nullptr, m = head, r = head->next;
		while (r) {
			m->next = l;
			l = r->next;
			r->next = m;
			ListNode *tmp = m;
			m = r;
			r = l;
			l = tmp;
		}
		return m;
	}
};

int main(void)
{
	
	return 0;
}
