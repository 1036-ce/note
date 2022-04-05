// url: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return nullptr;
		ListNode *dummy = new ListNode(0, head);
		ListNode *left = dummy, *right = head;
		while (right->next) {
			ListNode *tmp = right->next;
			if (tmp->val == right->val)
				right = right->next;
			else {
				if (right != left->next) {
					right = right->next;
					left->next = right;
				}
				else {
					right = right->next;
					left = left->next;
				}
			}
		}
		if (right != left->next) {
			right = right->next;
			left->next = right;
		}
		return dummy->next;
	}
};

int main(void)
{

	return 0;
}
