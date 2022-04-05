// url: https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class MedianFinder {
public:
	MedianFinder() {}

	void addNum(int num) {
		if (maxheap.empty() || num <= maxheap.top()) {
			maxheap.push(num);
			if (maxheap.size() - minheap.size() == 2) {
				minheap.push(maxheap.top());
				maxheap.pop();
			}
		}
		else {
			minheap.push(num);
			if (maxheap.size() < minheap.size()) {
				maxheap.push(minheap.top());
				minheap.pop();
			}
		}
	}

	double findMedian() {
		if (maxheap.size() == minheap.size())
			return (maxheap.top() + minheap.top()) / 2.0;
		else
			return maxheap.top();
	}
private:
	priority_queue<int, vector<int>, less<int>> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
};

int main(void)
{
	MedianFinder m;
	m.addNum(1);
	cout << m.findMedian() << endl;
	m.addNum(2);
	cout << m.findMedian() << endl;
	m.addNum(3);
	cout << m.findMedian() << endl;
	/* m.addNum(-4);
	 * cout << m.findMedian() << endl;
	 * m.addNum(-5);
	 * cout << m.findMedian() << endl;  */
	return 0;
}
