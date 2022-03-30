// url: https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/


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
	ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
		int len1 = 0, len2 = 0;
		ListNode *l1 = headA, *l2 = headB;

		while (l1) {
			l1 = l1->next;
			++len1;
		}

		while (l2) {
			l2 = l2->next;
			++len2;
		}

		l1 = headA, l2 = headB;
		if (len2 > len1) {
			int tmp = len2 - len1;
			while (tmp--)
				l2 = l2->next;
		}
		else {
			int tmp = len1 - len2;
			while (tmp--)
				l1 = l1->next;
		}
		while (l1 && l2) {
			if (l1 == l2)
				return l1;
			else {
				l1 = l1->next;
				l2 = l2->next;
			}
		}
		return nullptr;
	}
};

int main(void)
{
	
	return 0;
}
