#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	ostringstream strm(s);
	strm << "str";
	s = strm.str();
	cout << s << endl;
	return 0;
}
