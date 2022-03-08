#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	vector<char> vec{'a','b','c','d'};
	string s;
	for (auto i: vec)
		s += i;
	cout << s << endl;
	return 0;
}
