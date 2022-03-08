#include <iostream>
#include <iterator>
#include <string>

using namespace std;

void init(string &s)
{
	string target = "~&|()";
	string::size_type pos = 0;
	while ((pos = s.find_first_of(target, pos)) != string::npos)
	{
		auto ins = inserter(s, s.begin() + pos);
		*ins = ' ';
		ins = inserter(s, s.begin() + pos + 2);
		*ins = ' ';
		pos += 2;
	}
	cout << s << endl;
}

int main(void)
{
	string s("~(Alice)");
	init(s);

	return 0;
}
