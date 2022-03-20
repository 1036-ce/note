// url: https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {  }
};

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		ListNode *p = head;
		int a = 0;
		while (p) {
			p = p->next;
			++a;
		}
		vector<int> vec(a, 0);
		p = head;
		while (a > 0) {
			vec[a - 1] = p ->val;
			p = p->next;
			--a;
		}
		return vec;
	}
};

int main(void)
{
	return 0;
}
