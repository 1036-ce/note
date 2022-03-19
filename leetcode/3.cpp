// url: https://leetcode-cn.com/problems/add-two-numbers/

#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {  }
	ListNode(int x): val(x), next(nullptr) {  }
	ListNode(int x, ListNode* next): val(x), next(next) {  }
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *cur = new ListNode();
		ListNode *ret = cur;
		ListNode *pre = nullptr;
		int z = 0;
		while (l1 && l2) {
			int tmp = l1->val + l2->val + z;
			z = tmp / 10;
			cur->val = tmp % 10;

			ListNode *node = new ListNode();
			pre = cur;
			cur->next = node;
			cur = cur->next;
			l1 = l1->next;
			l2 = l2->next;
		}

		ListNode *l = l1 ? l1 : l2;
		while (l)
		{
			int tmp = l->val + z;
			z = tmp / 10;
			cur->val = tmp % 10;

			ListNode *node = new ListNode();
			pre = cur;
			cur->next = node;
			cur = cur->next;
			l = l->next;
		}

		if (z)
			cur->val = z;
		else
		{
			pre->next = nullptr;
			delete cur;
		}
		return ret;
	}
};

int main(void)
{
	
	return 0;
}
