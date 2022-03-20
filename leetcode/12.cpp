// url: https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {  }
};

class Solution {
public:
	ListNode *reverseList(ListNode *head) {
		ListNode *pre = nullptr, *cur = head;
		while (cur) {
			ListNode *tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return cur;
	}
};

int main(void)
{
	
	return 0;
}
