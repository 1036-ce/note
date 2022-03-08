#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sizeLess5(const string &s)
{
	return s.size() < 5;
}

int main(void)
{
	vector<string> vec;
	string word;
	while (cin >> word)
		vec.push_back(word);
	auto it = partition(vec.begin(), vec.end(), sizeLess5);
	for (;it != vec.end(); ++it)
		cout << *it << endl;
	return 0;
}

