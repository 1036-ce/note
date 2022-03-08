#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool isShorter(const string &s, int sz)
{
	return s.size() <= sz;
}

int main(int argc, char **argv)
{
	ifstream is(argv[1], ifstream::in);
	vector<string> vec;
	string word;
	while (is >> word)
		vec.push_back(word);
	int sz = 6;
	auto f = bind(isShorter, _1, sz);
	auto ans = count_if(vec.begin(), vec.end(), f);
	cout << ans << endl;
	return 0;
}

