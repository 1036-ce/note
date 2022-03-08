#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(void)
{
	string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	regex r(pattern);
	string s;
	smatch res;
	while (cin >> s)
	{
		if (regex_match(s, r))
			cout << "y" << endl;
		else
			cout << "n" << endl;
	}
	return 0;
}
