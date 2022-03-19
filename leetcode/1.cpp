// url: https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/solution/


#include <iostream>
#include <stack>

using namespace std;

class CQueue {
public:
	CQueue() {
	}
	
	void appendTail(int value) {
		s1.push(value);
	}

	int deleteHead() {
		if (s1.empty() && s2.empty())
			return -1;
		int ret;
		if (!s2.empty()) {
			ret = s2.top();
			s2.pop();
			return ret;
		}

		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		ret = s2.top();
		s2.pop();
		return ret;
	}
private:
	stack<int> s1, s2;
};

int main(void)
{
	CQueue *obj = new CQueue();
	char op;
	int value;
	while (cin >> op)
	{
		if (op == 'a')
		{
			cin >> value;
			obj->appendTail(value);
		}
		else if (op == 'd')
			cout << obj->deleteHead() << endl;
	}
	return 0;
}
