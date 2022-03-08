#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	ifstream is(argv[1], ifstream::in);
	vector<string> vec;
	string word;
	while (is >> word)
		vec.push_back(word);
	int sz = 6;
	auto ans = count_if(vec.begin(), vec.end(),
			[sz] (const string &s) { return s.size() > sz; });
	cout << ans << endl;
	return 0;
}

