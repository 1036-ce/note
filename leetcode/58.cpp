// url: https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/

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
	ListNode* deleteNode(ListNode* head, int val) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;

		ListNode *tmp = dummy;
		while (tmp->next) {
			if (tmp->next->val == val) {
				tmp->next = tmp->next->next;
				return dummy->next;
			}
			else
				tmp = tmp->next;
		}
		return nullptr;
	}
};

int main(void)
{
	
	return 0;
}
