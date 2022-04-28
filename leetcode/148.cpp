// url: https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 单调队列
class MaxQueue {
public:
	MaxQueue() {
	}

	int max_value() {
		if (dq.empty())
			return -1;
		return dq.front();
	}

	void push_back(int value) {
		q.push(value);
		while (!dq.empty() && value >= dq.back())
			dq.pop_back();
		dq.push_back(value);
	}

	int pop_front() {
		if (q.empty())
			return -1;
		int ret = q.front();
		q.pop();
		if (ret == dq.front())
			dq.pop_front();
		return ret;
	}
private:
	queue<int> q;
	deque<int> dq;
};

int main(void)
{
	
	return 0;
}
