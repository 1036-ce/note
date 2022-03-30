// url: https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode *l2) {
		ListNode *ans = new ListNode(0);
		ListNode *head = ans;

		while (l1 && l2) {
			if (l1->val == l2->val) {
				ans->next = new ListNode(l1->val);
				ans = ans->next;
				ans->next = new ListNode(l2->val);
				ans = ans->next;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1->val < l2->val) {
				ans->next = new ListNode(l1->val);
				ans = ans->next;
				l1 = l1->next;
			}
			else {
				ans->next = new ListNode(l2->val);
				ans = ans->next;
				l2 = l2->next;
			}
		}

		if (l1)
			ans->next = l1;
		else if(l2)
			ans->next = l2;

		return head->next;
	}
};

int main(void)
{
	
	return 0;
}
