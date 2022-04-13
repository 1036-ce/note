#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <tuple>

using namespace std;

bool isNumber(string s) {
	string pattern("eE");
	stringstream is(s);
	is >> s;
	auto pos = s.find_first_of(pattern);
	if (pos == string::npos) {

	}
		// return isInteger(s) || isDecimal(s);
	else {
		string left = s.substr(0, pos);
		string right = s.substr(pos + 1, s.size() - pos);
		// return (isInteger(left) || isDecimal(left)) && isInteger(right);
	}
	return true;
}

int main(void)
{
	string s("   12   312   ");
	auto it = s.begin();
	while (*it == ' ') {
		s.erase(it);
		it = s.begin();
	}
	it = s.end() - 1;
	while (*it == ' ') {
		s.erase(it);
		it = s.end() - 1;
	}

	cout << s << 'a' << endl;
	return 0;
}
