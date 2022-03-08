#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void find_insert(forward_list<string> &lst, const string &s1, const string &s2)
{
	auto it = lst.begin();
	auto pre = lst.before_begin();
	while (it != lst.end()) {
		if (*it == s1) {
			lst.insert_after(it, s2);
			return;
		}
		++it;
		++pre;
	}
	lst.insert_after(pre, s2);
}

void show(forward_list<string> &lst)
{
	for (auto i: lst)
		cout << i << endl;
	cout << endl;
}
int main(void)
{
	forward_list<string> lst{"1", "12", "123", "1234", "12345"};
	show(lst);
	find_insert(lst, "4", "23");
	show(lst);
	find_insert(lst, "1", "23");
	show(lst);
	return 0;
}
