// url: https://leetcode-cn.com/problems/middle-of-the-linked-list/

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

// 快慢指针
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode *p1 = head, *p2 = head;

		int num = 0;
		while (p2) {
			p2 = p2->next;
			++num;
			if (num % 2 == 0)
				p1 = p1->next;
		}
		return p1;
	}
};

int main(void)
{
	
	return 0;
}
