#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void)
{
	list<string> ls;
	string s;
	while (cin >> s)
		ls.push_back(s);
	for (auto beg = ls.begin(); beg != ls.end(); ++beg)
		cout << *beg << endl;
	return 0;
}
