#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main(void)
{
	list<int> li{1,2,3,4,5,6,7,8,9};
	deque<int> odd, even;

	for (auto beg = li.begin(); beg != li.end(); ++beg) {
		if (*beg % 2)
			odd.push_back(*beg);
		else
			even.push_back(*beg);
	}
	for (auto i: odd)
		cout << i << endl;
	cout << endl;
	for (auto i: even)
		cout << i << endl;
	return 0;
}
