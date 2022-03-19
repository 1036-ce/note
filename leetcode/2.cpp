/* url: https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/ */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class MinStack {
public:
	MinStack() {
	}

	void push(int x) {
		s1.push(x);
		if (s2.empty() || s2.top() >= x)
			s2.push(x);
	}

	void pop() {
		if (s1.empty())
			return;
		int value = s1.top();
		s1.pop();
		if (value == s2.top())
			s2.pop();
	}

	int top() {
		return s1.top();
	}

	int min() {
		return s2.top();
	}
private:
	stack<int> s1, s2;
};

int main(void)
{
	MinStack *obj = new MinStack();
	string s;
	int value;
	while (cin >> s)
	{
		if (s == "push")
		{
			cin >> value;
			obj->push(value);
		}
		else if (s == "pop")
			obj->pop();
		else if (s == "min")
			cout << obj->min() << endl;
		else if (s == "top")
			cout << obj->top() << endl;
	}
	return 0;
}
