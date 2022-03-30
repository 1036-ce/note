// url: https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/

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
	ListNode* getKthFromEnd(ListNode *head, int k) {
		ListNode *l = head, *r = head;

		while (--k)
			r = r->next;

		while (r->next) {
			r = r->next;
			l = l->next;
		}
		return l;
	}
};

int main(void)
{
	
	return 0;
}
