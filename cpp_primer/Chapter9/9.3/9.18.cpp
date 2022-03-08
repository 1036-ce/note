#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void)
{
	deque<string> ds;
	string s;
	while (cin >> s)
		ds.push_back(s);
	for (auto beg = ds.begin(); beg != ds.end(); ++beg) 
		cout << *beg << endl;
	return 0;
}
