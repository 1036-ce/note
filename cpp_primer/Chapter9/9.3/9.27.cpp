#include <iostream>
#include <forward_list>

using namespace std;

int main(void)
{
	forward_list<int> lst{2,2,2,2};
	auto pre = lst.before_begin(), cur = lst.begin();
	while(cur != lst.end()) {
		if (*cur % 2)
			cur = lst.erase_after(pre);
		else {
			pre = cur;
			++cur;
		}
	}
	for (auto i: lst) 
		cout << i << endl;
	return 0;
}
